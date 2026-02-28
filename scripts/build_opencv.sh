#!/bin/bash
# 1. Клонируем исходный код OpenCV (версия 4.10.0)
git clone --depth 1 --branch 4.10.0 https://github.com/opencv/opencv.git

# 2. Переходим в папку со скриптами сборки
cd opencv

# 3. Запускаем официальный сборщик OpenCV для WebAssembly
# Это самая долгая часть — она превращает C++ исходники в WASM-библиотеку
python3 platforms/js/build_js.py build_wasm --build_wasm
