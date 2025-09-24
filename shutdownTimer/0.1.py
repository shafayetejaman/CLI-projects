import json
from datetime import datetime
import os
import time

DB_NAME = "DB.json"

while True:
    currentTime = datetime.now()
    timestamp = currentTime.timestamp()

    with open(DB_NAME, "r+") as file:
        try:
            data = json.load(file)
        except:
            data = {"bootTime": timestamp}

        data["upTime"] = timestamp

        # rewrite file properly
        file.seek(0)
        json.dump(data, file, indent=4)
        file.truncate()

        # calculate difference
        diff = data["upTime"] - data["bootTime"]

        if diff >= (3 * 60 * 60) - 10:  # 3 hours
            print(os.system("shutdown /s /t 10"))
            file.seek(0)
            file.truncate()
            break

    time.sleep(60 * 5)  # wait 5 minute
