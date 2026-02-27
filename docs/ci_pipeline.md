# ⚙️ CI/CD Pipeline: Automated WASM Engineering

This project leverages **GitHub Actions** to ensure a reproducible, automated build environment for custom OpenCV WebAssembly binaries.

## 🚀 The Workflow Logic
The pipeline is designed to eliminate the "it works on my machine" problem by containerizing the build environment.

### 1. Build Environment
- **OS:** Ubuntu Latest
- **Toolchain:** Emscripten (EMSDK)
- **Dependency Management:** Automatic caching of the OpenCV source tree to speed up subsequent builds.

### 2. Custom Compilation Stages
The workflow executes the following steps:
1. **Setup:** Installs Emscripten and clones the specified OpenCV version.
2. **Configuration:** Runs a Python-based configuration script to select only necessary modules (`core`, `imgproc`).
3. **Compilation:** Executes `emmake` to generate `cv.wasm` and `cv.js`.
4. **Artifacts:** Packages the optimized binaries for deployment.

## 🛠 Reproducibility
Every commit triggers a verification build. This ensures that:
- The C++ code is compatible with the Emscripten version.
- The custom module selection doesn't break library dependencies.
- The final WASM binary is ready for production use.

## 📊 Status Badges
*(Add your GitHub Actions badge here to show the live build status)*
