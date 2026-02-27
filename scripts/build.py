import os
import subprocess
import sys

def build():
    print("🚀 Собираем проект через Emscripten Ports...")
    
    command = [
        "emcc", "src/main.cpp",
        "-o", "index.js",
        "--bind",                      # Связь C++ и JS
        "-s", "USE_OPENCV=1",          # МАГИЯ: Emscripten сам скачает OpenCV
        "-s", "ALLOW_MEMORY_GROWTH=1",
        "-O3"
    ]

    print(f"🔨 Выполняем: {' '.join(command)}")
    result = subprocess.run(command)
    
    if result.returncode == 0:
        print("✅ ПОБЕДА! Файлы готовы.")
    else:
        print("❌ Ошибка сборки.")
        sys.exit(1)

if __name__ == "__main__":
    build()
