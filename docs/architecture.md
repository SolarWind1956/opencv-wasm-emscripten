# 🏗 System Architecture

This document describes the internal structure of the OpenCV-WASM EcoMonitor and how C++ logic interacts with the WebAssembly environment.

## 1. High-Level Overview
The project follows a "Native-to-Web" transformation pattern:
- **Core Logic:** Written in C++ using OpenCV.
- **Compilation:** Emscripten translates C++ into WASM/JS glue code.
- **Frontend:** A lightweight HTML/JS wrapper that manages the WASM lifecycle and provides data (images/video) to the engine.

## 2. OpenCV Integration
We use a modular approach to OpenCV:
- **Processing Pipeline:** [Опишите кратко, что делает ваш алгоритм, например: Image filtering -> Grayscale conversion -> Edge detection].
- **Memory Management:** Efficient data transfer between JavaScript `Uint8Array` and OpenCV `cv::Mat`.

## 3. Data Flow
1. **Input:** Browser captures video/image.
2. **Bridge:** Data is copied to the Emscripten heap.
3. **Execution:** WASM module processes the buffer using OpenCV functions.
4. **Output:** The processed frame is rendered back to a `<canvas>`.

## 4. Build System
The build is orchestrated via Python scripts and CMake, ensuring that the same environment can be reproduced both locally and in GitHub Actions.
