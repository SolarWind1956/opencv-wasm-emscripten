#!/bin/bash
# 1. Клонируем исходный код OpenCV (версия 4.10.0)
git clone --depth 1 --branch 4.10.0 https://github.com/opencv/opencv.git

# 2.  
echo "--- Начинаем сборку с флагом C++17 ---"
# Мы добавляем переменную CMAKE_CXX_FLAGS, чтобы исправить ошибку
python3 opencv/platforms/js/build_js.py build_wasm --build_wasm --cmake_option="-DCMAKE_CXX_FLAGS=-std=c++17"
