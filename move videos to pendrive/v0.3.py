from os import path
from glob import glob
from time import perf_counter, sleep
from subprocess import run
from alive_progress import alive_bar

SRC_DIR = "F:\\Downloads\\Video"
DIST_DIR = "H:\\New folder"

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

startTime = perf_counter()


def move_file(src):
    print("moving.........")
    dist = path.join(DIST_DIR, path.basename(src))
    print(f"{src} -> {dist}")
    try:
        run(["move", src, dist], shell=True, check=True)
    except Exception as e:
        print("Error: ", e)


with alive_bar(len(allFiles)) as bar:
    for fileName in allFiles:
        move_file(fileName)
        bar(1)


# 18 second
