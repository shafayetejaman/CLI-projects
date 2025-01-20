from os import path
from glob import glob
from time import perf_counter
from concurrent.futures import ThreadPoolExecutor
from subprocess import run, CalledProcessError

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

threads = []

startTime = perf_counter()


def move_file(src):
    print("copying.........")
    dist = path.join(DIST_DIR, path.basename(src))
    try:
        run(["move", src, dist], shell=True, check=True)
    except Exception as e:
        print("Error: ", e)

    print(f"Moved {src} -> {dist}")


with ThreadPoolExecutor(max_workers=2) as executor:
    executor.map(move_file, allFiles)


print("complete. Took: ", round(perf_counter() - startTime, 2), "S")
# 28 second
