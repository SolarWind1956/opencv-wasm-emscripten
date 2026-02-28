#!/bin/bash
# 1. Клонируем (если папки нет)
if [ ! -d "opencv" ]; then
  git clone --depth 1 --branch 4.10.0 https://github.com/opencv/opencv.git
fi

# 2. Устанавливаем флаги на уровне системы (Environment Variables)
# Это принудительно заставит em++ использовать стандарт C++17
export CXXFLAGS="-std=c++17"
export CFLAGS="-std=c11"

echo "--- Начинаем принудительную сборку C++17 ---"

# 3. Запуск сборки с дублированием флагов в CMake
python3 opencv/platforms/js/build_js.py build_wasm --build_wasm \
  --cmake_option="-DCMAKE_CXX_STANDARD=17" \
  --cmake_option="-DCMAKE_CXX_STANDARD_REQUIRED=ON" \
  --cmake_option="-DCMAKE_CXX_FLAGS=-std=c++17"

