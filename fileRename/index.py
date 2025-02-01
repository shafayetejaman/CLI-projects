from re import sub
from os import path, rename
from glob import glob


PATTERN = "^(\\d\\d?\\.\\s)?(Watch\\s)?"

SRC_DIR = "F:\\Downloads\\Video"

VIDEO_FORMATS = [
    ".mp4",
    ".mkv",
    ".avi",
    ".mov",
    ".wmv",
    ".flv",
    ".webm",
    ".m4v",
    ".3gp",
    ".mpg",
    ".mpeg",
    ".ts",
]

allFiles = []

for ext in VIDEO_FORMATS:
    allFiles += glob(path.join(SRC_DIR, f"*{ext}"))

for fileName in allFiles:
    newBaseName = sub(string=path.basename(fileName), pattern=PATTERN, repl="")
    newFilePath = path.join(SRC_DIR, newBaseName)
    print(fileName," -> ", newFilePath)
    rename(src=fileName, dst=newFilePath)
