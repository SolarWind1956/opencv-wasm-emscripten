
# ⚡ WebAssembly & Emscripten Implementation

This project uses a **custom-built OpenCV WASM binary** instead of the generic `opencv.js`. This allows for a significantly smaller footprint and better performance.

## 🛠 Custom Build Process
We use Emscripten (EMSDK) to compile a subset of OpenCV modules.
- **Target Modules:** `core`, `imgproc`, `objdetect`.
- **Optimization Level:** `-O3` for maximum execution speed.
- **Size Optimization:** Only essential functions are exported to minimize the `.wasm` file size.

## 🏗 Bridge & Glue Code
- **Embind:** We use `embind` to create seamless bindings between C++ classes and JavaScript.
- **Memory Management:** Manual memory handling is used to prevent leaks when passing `cv::Mat` objects between JS and WASM.

## 🚀 Performance Gains
By stripping out unused modules (like `videoio` or `highgui` which aren't needed in the browser), we achieve:
1. **Faster Load Times:** Smaller binary size.
2. **Reduced Memory Overhead:** Optimized heap allocation.
