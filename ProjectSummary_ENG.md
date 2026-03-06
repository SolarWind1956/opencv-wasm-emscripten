# 📋 Project Summary: OpenCV-WASM EcoMonitor
Version 0.7.1

## 1. Vision & Background
**Development of a distributed, automated system for marine water pollution monitoring using cloud technologies and computer vision**.

**Bio-indicator approach**: Utilizing mussel colonies as natural indicators of water quality.

**Hardware**: Submerged, vacuum-sealed videocamera modules deployed near shellfish beds.

**Core logic**: Real-time video analysis and remote cloud-based sensor calibration to ensure data accuracy in underwater conditions.

## 2. Technical Stack & Constraints
**Engine**: C++ / OpenCV 4.9.0 (Custom Lightweight Build).

**Compiler**: Emscripten 3.x.x (Targeting WebAssembly).

**CI/CD**: GitHub Actions (Runner: ubuntu-latest).

**Optimization**: Minimalist footprint — only core and imgproc modules compiled into libopencv_world.a.

**Runtime**: Pure Web environment (No Node.js dependency), Static Linking.

## 3. Project Contributors

**AI on Google Search** - Thought Partner.

**ChatGPT (OpenAI)** - Thought Partner.

**Viktor Gnyubkin** - biologist

**Sergej Heckel (@SolarWind1956)** - Lead Engineer & Architect.

## 4. Current Status: SUCCESS ✅
**Milestone**: Stable C++ ↔ JS communication via Emscripten Bindings.

**Feature**: Real-time Canny edge detection running in the browser.

**Reference**: Verified build achieved in commit efa407a.
