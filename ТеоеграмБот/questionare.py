import telebot
from telebot.types import InlineKeyboardMarkup, InlineKeyboardButton, ReplyKeyboardMarkup, KeyboardButton


bot = telebot.TeleBot('7221571794:AAHavgln73Hx4OfrCLwbAvczkptlTMpJVLI')


giveaways = {}

# Главный обработчик команды /start
@bot.message_handler(commands=['start'])
def start(message):
    markup = ReplyKeyboardMarkup(resize_keyboard=True)
    markup.add(KeyboardButton("Создать опрос"), KeyboardButton("Создать тест"))
    bot.send_message(message.chat.id, 
                     "Добро пожаловать в бота для проведения опроссов и тестов!\nВыберите действие ниже:", 
                     reply_markup=markup)


bot.polling()