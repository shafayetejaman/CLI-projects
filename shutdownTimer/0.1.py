import json
from datetime import datetime
import os
import time
from enum import Enum


class Keys(str, Enum):
    bootTime = "bootTime"
    upTime = "upTime"
    lastShutdown = "lastShutdown"


DB_NAME = "C:\\Users\\Shafayet\\shutdownTimer\\DB.json"

while True:
    currentTime = datetime.now()
    timestamp = currentTime.timestamp()
    currentDate = currentTime.date().strftime("%d/%m")

    with open(DB_NAME, "r+") as file:
        try:
            data = json.load(file)
        except:
            data = {Keys.bootTime: timestamp}

        # if already shutdown for the day
        if data.get(Keys.lastShutdown) == currentDate:
            os.system("shutdown /s /t 1")

        # update uptime
        data[Keys.upTime] = timestamp

        # rewrite file
        file.seek(0)
        json.dump(data, file, indent=4)
        file.truncate()

        # calculate difference
        diff = data.get(Keys.upTime, 0) - data.get(Keys.bootTime, 0)

        if diff >= (3 * 60 * 60) - 10:  # 3 hours
            print(os.system("shutdown /s /t 10"))
            file.seek(0)
            file.truncate()
            data = {Keys.lastShutdown: currentDate}
            json.dump(data, file)
            break

    time.sleep(60 * 2)  # wait 2 minutes
