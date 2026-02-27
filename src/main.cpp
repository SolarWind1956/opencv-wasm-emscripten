#include <iostream>
#include <opencv2/core.hpp>

int main() {
    // Выводим приветствие и версию OpenCV
    std::cout << "OpenCV-WASM EcoMonitor initialized!" << std::endl;
    std::cout << "OpenCV Version: " << CV_VERSION << std::endl;
    
    return 0;
}
