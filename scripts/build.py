import os
import subprocess
import sys

def build():
    print("🚀 Собираем проект...")
    command = [
        "emcc", "src/main.cpp",
        "-o", "index.js",
        "-Iinclude",
        "--bind",
        "-s", "ALLOW_MEMORY_GROWTH=1",
        "-O3"
    ]
    result = subprocess.run(command)
    if result.returncode == 0:
        print("✅ Готово!")
    else:
        sys.exit(1)

if __name__ == "__main__":
    build()
