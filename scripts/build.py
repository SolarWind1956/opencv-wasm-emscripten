import os, subprocess, sys

def build():
    print("🚀 Собираем ядро WASM с путями к OpenCV...")
    
    # Путь к папке, которую мы создали в build.yml
    opencv_include = "opencv-wasm/include"
    
    command = [
        "emcc", "src/main.cpp",
        "-o", "index.js",
        "--bind",
        f"-I{opencv_include}",  # Указываем компилятору, где искать .hpp
        "-s", "ALLOW_MEMORY_GROWTH=1",
        "-O3"
    ]
    
    print(f"Выполняю команду: {' '.join(command)}")
    result = subprocess.run(command)
    
    if result.returncode == 0:
        print("✅ Сборка готова! Файлы index.js и index.wasm созданы.")
    else:
        print("❌ Ошибка компиляции. Проверьте логи выше.")
        
    sys.exit(result.returncode)

if __name__ == "__main__":
    build()


