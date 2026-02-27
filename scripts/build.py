import os
import subprocess
import sys

def build():
    print("🚀 Начинаем сборку OpenCV-WASM EcoMonitor...")
    
    # Создаем папку для вывода, если её нет
    if not os.path.exists('web'):
        os.makedirs('web')

    # Команда компиляции
    # --bind включает EMSCRIPTEN_BINDINGS
    # -Iinclude указывает на ваши скачанные заголовки
    # -s ALLOW_MEMORY_GROWTH=1 позволяет WASM расширять память
    command = [
        "emcc", "src/main.cpp",
        "-o", "index.js",
        "-Iinclude",
        "--bind",
        "-s", "ALLOW_MEMORY_GROWTH=1",
        "-s", "NO_EXIT_RUNTIME=1",
        "-O3"
    ]

    print(f"🔨 Выполняем: {' '.join(command)}")
    
    result = subprocess.run(command)
    
    if result.returncode == 0:
        print("✅ Сборка успешно завершена! Файлы index.js и index.wasm готовы.")
    else:
        print("❌ Ошибка при сборке.")
        sys.exit(1)

if __name__ == "__main__":
    build()
