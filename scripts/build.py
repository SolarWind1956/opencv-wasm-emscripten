import os, subprocess, sys

def build():
    print("🚀 Собираем ядро WASM (Финальный штурм #98)...")
    
    # Пути к ресурсам, которые мы подготовили в GitHub Actions
    opencv_include = "opencv-wasm/include"
    opencv_lib_dir = "opencv-wasm/lib"
    
    command = [
        "emcc", "src/main.cpp",
        "-o", "index.js",
        "--bind",
        f"-I{opencv_include}",
        "-O3",
        f"-L{opencv_lib_dir}",
        "-lopencv_imgproc",
        "-lopencv_core", 
        "-lzlib",
        "-s", "ALLOW_MEMORY_GROWTH=1",
        "-s", "USE_PTHREADS=0",
        "-s", "ERROR_ON_UNDEFINED_SYMBOLS=1", # Теперь включаем проверку, файл должен найтись!
    ]
    
    print(f"Выполняю команду: {' '.join(command)}")
    result = subprocess.run(command)
    
    if result.returncode == 0:
        print("✅ УСПЕХ! Мы подружили C++ и OpenCV в облаке!")
    else:
        print("❌ Ошибка компоновки. Проверьте логи выше.")
        
    sys.exit(result.returncode)

if __name__ == "__main__":
    build()


