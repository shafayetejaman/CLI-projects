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
TOTAL_TIME = (3 * 60 * 60) - 10


while True:
    currentTime = datetime.now()
    currentDate = currentTime.date().strftime("%d/%m")

    with open(DB_NAME, "r+") as file:
        try:
            data = json.load(file)
        except:
            data = {}

        # reset counters
        if data.get(Keys.bootDate) != currentDate:
            data = {Keys.bootDate: currentDate, Keys.upTime: 0}

        # if already shutdown for the day
        if data.get(Keys.lastShutdown) == currentDate:
            subprocess.run(["shutdown", "-h", "now"])
            break

        # add 2 minutes uptime
        data[Keys.upTime] = data.get(Keys.upTime, 0) + 120

        # rewrite file
        file.seek(0)
        json.dump(data, file, indent=4)
        file.truncate()

        # check if uptime >= total time
        if data.get(Keys.upTime, 0) >= TOTAL_TIME:
            subprocess.run(["shutdown", "-h", "now"])
            file.seek(0)
            file.truncate()
            data = {Keys.lastShutdown: currentDate}
            json.dump(data, file)
            break

    time.sleep(60 * 2)  # wait 2 minutes
