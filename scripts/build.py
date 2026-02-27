import os
import subprocess
import sys

def build_project():
    print("🚀 Starting PRODUCTION build for OpenCV-WASM EcoMonitor...")
    
    # Путь к выходному файлу в папке web
    out_file = "web/index.js"
    src_file = "src/main.cpp"

    # Команда компиляции Emscripten
    # -s WASM=1: генерируем WebAssembly
    # -o: куда положить результат
    command = [
        "emcc", src_file,
        "-o", out_file,
        "-s", "WASM=1",
        "-s", "ALLOW_MEMORY_GROWTH=1",
        "-O3" # Максимальная оптимизация скорости
    ]

    try:
        print(f"🔨 Compiling {src_file}...")
        subprocess.run(command, check=True)
        print(f"✅ Success! Generated: {out_file}")
    except Exception as e:
        print(f"❌ Build failed: {e}")
        sys.exit(1)

if __name__ == "__main__":
    build_project()
