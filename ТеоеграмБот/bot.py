import telebot
from telebot.types import InlineKeyboardMarkup, InlineKeyboardButton, ReplyKeyboardMarkup, KeyboardButton


bot = telebot.TeleBot('7984540566:AAGw0uBSlnhHyAaBWFUsLU9fGFaNsjpbb0s')

# Словарь для хранения данных о розыгрышах
giveaways = {}

# Главный обработчик команды /start
@bot.message_handler(commands=['start'])
def start(message):
    markup = ReplyKeyboardMarkup(resize_keyboard=True)
    markup.add(KeyboardButton("🎉 Новый розыгрыш"), KeyboardButton("➕ Добавить канал"))
    bot.send_message(message.chat.id, 
                     "Добро пожаловать в бота для проведения розыгрышей!\nВыберите действие ниже:", 
                     reply_markup=markup)

# Обработчик кнопки "Новый розыгрыш"
@bot.message_handler(func=lambda message: message.text == "🎉 Новый розыгрыш")
def new_giveaway(message):
    markup = InlineKeyboardMarkup()
    markup.add(InlineKeyboardButton("Продолжить", callback_data="new_giveaway"))
    bot.send_message(message.chat.id, 
                     "Вы выбрали создание нового розыгрыша. Нажмите 'Продолжить', чтобы начать настройку.", 
                     reply_markup=markup)

# Обработчик инлайн-кнопок
@bot.callback_query_handler(func=lambda call: True)
def callback_inline(call):
    if call.data == "new_giveaway":
        bot.send_message(call.message.chat.id, 
                         "Введите описание розыгрыша (например, приз, условия и дату завершения):")
        bot.register_next_step_handler(call.message, get_giveaway_details)

def get_giveaway_details(message):
    giveaway_id = len(giveaways) + 1
    giveaways[giveaway_id] = {"details": message.text, "participants": []}
    markup = InlineKeyboardMarkup()
    markup.add(InlineKeyboardButton("Участвовать", callback_data=f"join_{giveaway_id}"))
    bot.send_message(message.chat.id, 
                     f"Розыгрыш создан!\n\nОписание:\n{message.text}\n\nПоделитесь этим сообщением для участия!",
                     reply_markup=markup)

@bot.callback_query_handler(func=lambda call: call.data.startswith("join_"))
def join_giveaway(call):
    giveaway_id = int(call.data.split("_")[1])
    if call.from_user.id not in giveaways[giveaway_id]["participants"]:
        giveaways[giveaway_id]["participants"].append(call.from_user.id)
        bot.answer_callback_query(call.id, "Вы успешно зарегистрированы!")
    else:
        bot.answer_callback_query(call.id, "Вы уже участвуете в этом розыгрыше.")

# Запуск бота
bot.infinity_polling()

