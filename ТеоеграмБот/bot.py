from aiogram import Bot, Dispatcher, types
from aiogram.types import InlineKeyboardButton, InlineKeyboardMarkup, ReplyKeyboardMarkup, KeyboardButton
from aiogram.filters import Command
import pymongo
from pymongo import MongoClient
import datetime
import logging
from dotenv import load_dotenv
import os
import asyncio
from aiogram import Router
from bson import ObjectId

# Загружаю переменные из .env
load_dotenv()

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

API_TOKEN = os.getenv("TELEGRAM_API_TOKEN")
MONGO_URI = os.getenv("MONGO_URI")

client = MongoClient(MONGO_URI)
db = client['test']
polls_collection = db['tests']

bot = Bot(token=API_TOKEN)
router = Router()
dp = Dispatcher()

active_poll = {}

start_keyboard = ReplyKeyboardMarkup(
    keyboard=[
        [KeyboardButton(text="📊 Пройти опрос")],
        [KeyboardButton(text="➕ Создать опрос")]
    ],
    resize_keyboard=True
)

finish_keyboard = ReplyKeyboardMarkup(
    keyboard=[[KeyboardButton(text="✅ Завершить создание опроса")]],
    resize_keyboard=True
)

@router.message(Command(commands=["start"]))
async def start_command(message: types.Message):
    await message.answer(
        "Добро пожаловать в бота для проведения массовых опросов!\nВыберите действие ниже:",
        reply_markup=start_keyboard
    )

@router.message(lambda message: message.text == "➕ Создать опрос")
async def create_poll_start(message: types.Message):
    active_poll[message.from_user.id] = {"title": None, "questions": [], "state": "waiting_for_title"}
    await message.answer("Введите название (title) для нового опроса:")

@router.message(lambda message: message.from_user.id in active_poll and active_poll[message.from_user.id]["state"] == "waiting_for_title")
async def set_poll_title(message: types.Message):
    active_poll[message.from_user.id]["title"] = message.text
    active_poll[message.from_user.id]["state"] = "waiting_for_question"
    await message.answer(f"Название опроса установлено: {message.text}\nТеперь введите вопрос для опроса:", reply_markup=finish_keyboard)

@router.message(lambda message: message.from_user.id in active_poll and active_poll[message.from_user.id]["state"] == "waiting_for_question")
async def add_poll_question(message: types.Message):
    if message.text == "✅ Завершить создание опроса":
        await finish_poll_creation(message)
        return

    active_poll[message.from_user.id]["questions"].append({"question": message.text, "options": []})
    active_poll[message.from_user.id]["state"] = "waiting_for_options"
    await message.answer(f"Вопрос добавлен: {message.text}\nТеперь введите варианты ответа через запятую:")

@router.message(lambda message: message.from_user.id in active_poll and active_poll[message.from_user.id]["state"] == "waiting_for_options")
async def add_poll_options(message: types.Message):
    if message.text == "✅ Завершить создание опроса":
        await finish_poll_creation(message)
        return

    options = [opt.strip() for opt in message.text.split(",")]
    if not options:
        await message.answer("Вы не указали варианты ответа. Попробуйте снова.")
        return

    active_poll[message.from_user.id]["questions"][-1]["options"] = options
    active_poll[message.from_user.id]["state"] = "waiting_for_question"
    await message.answer(f"Варианты добавлены: {', '.join(options)}\nВведите следующий вопрос или завершите создание опроса.")

async def save_poll_to_db(user_id, title, questions):
    poll_data = {
        "user_id": user_id,
        "title": title,
        "questions": questions,
        "created_at": datetime.datetime.now()
    }
    result = polls_collection.insert_one(poll_data)
    return result.inserted_id

async def finish_poll_creation(message: types.Message):
    user_id = message.from_user.id
    if user_id not in active_poll or not active_poll[user_id]["questions"]:
        await message.answer("Вы ещё не добавили ни одного вопроса!", reply_markup=start_keyboard)
        return

    try:
        title = active_poll[user_id]["title"]
        questions = active_poll[user_id]["questions"]
        poll_id = await save_poll_to_db(user_id, title, questions)

        poll_summary = "\n".join(
            f"{i}. {question['question']}\nВарианты: {', '.join(question['options'])}"
            for i, question in enumerate(questions, 1)
        )

        await message.answer(f"Опрос завершен и сохранен в базе данных! ID опроса: {poll_id}\n"
                             f"Название: {title}\nВот ваш опрос:\n{poll_summary}")
    except Exception as e:
        logger.error(f"Ошибка при сохранении опроса: {e}")
        await message.answer("Произошла ошибка при сохранении опроса. Попробуйте снова.")
    finally:
        del active_poll[user_id]
        await message.answer("Вы вышли из режима создания опроса.", reply_markup=start_keyboard)

@router.message(lambda message: message.text == "📊 Пройти опрос")
async def send_polls(message: types.Message):
    data = polls_collection.find()  # Получаем данные из базы

    if polls_collection.count_documents({}) == 0:
        await message.reply("В базе данных нет доступных опросов!")
        return

    # Создаем клавиатуру для инлайн кнопок
    inline_keyboard = [
        [InlineKeyboardButton(text=item.get("title", f"Опрос {item['_id']}"), callback_data=f"poll_{item['_id']}")]
        for item in data
    ]

    # Create the InlineKeyboardMarkup with inline_keyboard
    keyboard = InlineKeyboardMarkup(inline_keyboard=inline_keyboard)

    # Отправляем сообщение с кнопками
    await message.reply("Выберите опрос для участия:", reply_markup=keyboard)

@router.callback_query(lambda query: query.data.startswith("poll_"))
async def handle_poll_selection(callback_query: types.CallbackQuery):
    poll_id = callback_query.data.split("_")[1]
    poll_data = polls_collection.find_one({"_id": ObjectId(poll_id)})

    if not poll_data:
        await callback_query.answer("Опрос не найден!")
        return

    title = poll_data.get("title", "Опрос без названия")
    questions = poll_data.get("questions", [])

    # Отправляем заголовок опроса
    await bot.send_message(callback_query.from_user.id, f"📋 **{title}**", parse_mode="Markdown")

    for question_data in questions:
        questionText = question_data.get("questionText", "Вопрос отсутствует")
        options = question_data.get("options", [])

        if options:
            await bot.send_poll(
                chat_id=callback_query.from_user.id,
                question=questionText,
                options=options,
                is_anonymous=False
            )
        else:
            await bot.send_message(callback_query.from_user.id, f"Вопрос \"{question}\" не имеет вариантов ответа.")

async def main():
    await bot.delete_webhook(drop_pending_updates=True)
    logger.info("Бот запущен!")
    dp.include_router(router)
    await dp.start_polling(bot)

if __name__ == "__main__":
    asyncio.run(main())
