from os import path
from shutil import move
from glob import glob
from threading import Thread
from time import perf_counter
from concurrent.futures import ThreadPoolExecutor

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

# for fileName in allFiles:
#     distPath = path.join(DIST_DIR, path.basename(fileName))

#     print("copying.........")
#     thread = Thread(target=move, args=(fileName, distPath))
#     print(f"{fileName} -> {distPath}")

#     thread.start()
#     threads.append(thread)

# for thread in threads:
#     thread.join()


def move_file(src):
    print("copying.........")
    dist = path.join(DIST_DIR, path.basename(src))
    move(src, dist)
    print(f"Moved {src} -> {dist}")


with ThreadPoolExecutor(max_workers=8) as executor:
    executor.map(move_file, allFiles)


print("complete. Took: ", round(perf_counter() - startTime, 2), "S")
# 69 second