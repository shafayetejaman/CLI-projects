import json
from datetime import datetime
import subprocess
import time
from enum import Enum


class Keys(str, Enum):
    bootDate = "bootDate"
    upTime = "upTime"
    lastShutdown = "lastShutdown"


DB_NAME = "/mnt/HDD/Downloads/Documents/workspace/CLI-projects/shutdownTimer/DB.json"
TOTAL_TIME = (3 * 60 * 60) - (3 * 60) - 10


def sleep(minutes: int = 2):
    time.sleep(60 * minutes)


def shutdown(minutes: int = 1):
    subprocess.run(
        ["notify-send", "-t", "10000", f"   Shutting down in {minutes} min"]
    )
    subprocess.run(["shutdown", "-h", str(minutes)])


print("Timer started")
subprocess.run(["notify-send", "-t", "20000", "   Shutdown Timer started"])

sleep()

#
# # shutdown if it earlyer then 11:00
# def check_morning():
#     currentTime = datetime.now()
#     currentDate = currentTime.time()
#     hour = currentDate.hour
#     if hour <= 11:
#         shutdown()
#         exit(-1)
#
#
# check_morning()
#

while True:
    currentTime = datetime.now()
    currentDate = currentTime.date().strftime("%d/%m")

    with open(DB_NAME, "r+") as file:
        try:
            data = json.load(file)
        except Exception as e:
            print(e)
            data = {}

        # if already shutdown for the day
        if data.get(Keys.lastShutdown) == currentDate:
            shutdown()
            break

        # reset counters
        if data.get(Keys.bootDate) != currentDate:
            data = {Keys.bootDate: currentDate, Keys.upTime: 0}

        # add 2 minutes uptime
        data[Keys.upTime] = data.get(Keys.upTime, 0) + 120

        # rewrite file
        file.seek(0)
        json.dump(data, file, indent=4)
        file.truncate()

        # check if uptime >= total time
        if data.get(Keys.upTime, 0) >= TOTAL_TIME:
            shutdown()
            file.seek(0)
            file.truncate()
            data = {Keys.lastShutdown: currentDate}
            json.dump(data, file)
            break

        sleep()
