#!/bin/bash
# 1. Клонируем (если папки нет)
if [ ! -d "opencv" ]; then
  git clone --depth 1 --branch 4.10.0 https://github.com/opencv/opencv.git
fi

# 2. Сборка с жестким указанием стандарта C++17
# Мы добавляем OPENCV_FORCE_PYTHON_CTYPES и CMAKE_CXX_STANDARD
python3 opencv/platforms/js/build_js.py build_wasm --build_wasm \
  --cmake_option="-DCMAKE_CXX_STANDARD=17" \
  --cmake_option="-DCMAKE_CXX_FLAGS=-std=c++17" \
  --cmake_option="-DCMAKE_C_FLAGS=-std=c11"

  
