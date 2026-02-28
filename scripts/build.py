import os, subprocess, sys

def build():
    print("🚀 Собираем ядро WASM (базовая версия)...")
    command = [
        "emcc", "src/main.cpp",
        "-o", "index.js",
        "--bind",
        "-s", "ALLOW_MEMORY_GROWTH=1",
        "-O3"
    ]
    result = subprocess.run(command)
    if result.returncode == 0:
        print("✅ Базовая сборка готова!")
    sys.exit(result.returncode)

if __name__ == "__main__":
    build()

