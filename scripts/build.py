import os, subprocess, sys

def build():
    print("🚀 Собираем ядро WASM (Финальный штурм)...")
    
    opencv_include = "opencv-wasm/include"
    
    command = [
        "emcc", "src/main.cpp",
        "-o", "index.js",
        "--bind",
        f"-I{opencv_include}",
        "-s", "ALLOW_MEMORY_GROWTH=1",
        "-s", "ERROR_ON_UNDEFINED_SYMBOLS=0", # МАГИЧЕСКАЯ СТРОКА 1
        "-s", "WARN_ON_UNDEFINED_SYMBOLS=0",  # МАГИЧЕСКАЯ СТРОКА 2
        "-O3"
    ]
    
    print(f"Выполняю команду: {' '.join(command)}")
    result = subprocess.run(command)
    
    if result.returncode == 0:
        print("✅ УСПЕХ! Мы подружили C++ и OpenCV в облаке!")
    sys.exit(result.returncode)

if __name__ == "__main__":
    build()


