import sys
import pytz
from pytz import timezone
import requests
import json
from datetime import datetime
from twilio.rest import Client
import python_weather
import time
import schedule





BASE_URL ="https://api.openweathermap.org/data/2.5/weather?"

API_KEY = "a7442951786c78d4e3ec288b112505f2"

CITY = ["Woodbury", " Montebello"]
ZIP_CODE = ["08096", "90640"]

url = BASE_URL + "zip=" + ZIP_CODE[0] + "&appid=" + API_KEY 
url2 = BASE_URL + "zip=" + ZIP_CODE[1] + "&appid=" + API_KEY 

response = requests.get(url).json()
response2 = requests.get(url2).json()


def kelvin_to_celcius(kelvin):
    celcius = kelvin - 273.15
    fehrenheit = (celcius * 9/5) + 32
    return celcius,fehrenheit



temp_kelvin = response['main']['temp']
temp_celcius,temp_fahrenheit = kelvin_to_celcius(temp_kelvin)

feels_like_kelvin = response['main']['feels_like']
fl_celcius, fl_fehrenheit = kelvin_to_celcius(feels_like_kelvin)

city_desc = response['weather'][0]['description']

temp_kelvin2 = response2['main']['temp']
temp_celcius2,temp_fahrenheit2 = kelvin_to_celcius(temp_kelvin2)

feels_like_kelvin2 = response2['main']['feels_like']
fl_celcius2, fl_fehrenheit2 = kelvin_to_celcius(feels_like_kelvin2)

city_desc2 = response2['weather'][0]['description']

################################################################################################################################

account_sid = "ACf2eb5a34f789f0a4352c1280abb54d35"

auth_token = "2291efc1a2e0dc92355079048aae260d"


client = Client(account_sid,auth_token)


client.region = 'us1'
client.edge = 'ashburn'


def text_message():
    message = client.messages.create(to = "+16094391697", from_ = "+18773721513", body = f"Its {city_desc} in {CITY[0]} Today, The Temperature is {temp_fahrenheit:.2f}°F But Feels like {fl_fehrenheit:.2f}°F")
    olivia_message = client.messages.create(to = "+13236701350", from_ = "+18773721513", body = f"Its {city_desc2} in {CITY[1]} Today, The Temperature is {temp_fahrenheit2:.2f}°F But Feels like {fl_fehrenheit2:.2f}°F")

schedule.every().day.at('09:00').do(text_message)



while True:
    schedule.run_pending()
    time.sleep(1)
