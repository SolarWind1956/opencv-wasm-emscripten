import os, subprocess, sys

def build():
    print("🚀 Начинаем сборку проекта с OpenCV...")
    
    # Пути к скачанной библиотеке (подставим те, что распаковались)
    opencv_path = "opencv-wasm" 
    
    command = [
        "emcc", "src/main.cpp",
        "-o", "index.js",
        "--bind",
        f"-I{opencv_path}/include",        # Где искать заголовки .hpp
        f"-L{opencv_path}/lib",            # Где искать файлы .a
        "-lopencv_imgproc",                # Модуль обработки изображений
        "-lopencv_core",                   # Ядро OpenCV
        "-s", "ALLOW_MEMORY_GROWTH=1",
        "-s", "MODULARIZE=1",
        "-O3"
    ]
    
    print(f"Выполняю команду: {' '.join(command)}")
    result = subprocess.run(command)
    
    if result.returncode == 0:
        print("✅ Успех! index.js и index.wasm готовы.")
    else:
        print("❌ Ошибка компиляции.")
    
    sys.exit(result.returncode)

if __name__ == "__main__":
    build()
