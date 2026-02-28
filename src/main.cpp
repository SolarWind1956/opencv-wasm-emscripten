#include <opencv2/core.hpp>
#include <emscripten/bind.h>
#include <iostream>

using namespace emscripten;

class EcoMonitor {
public:
    EcoMonitor() {}

    // Пока сделаем заглушку, чтобы проверить, что cv::Mat работает
    std::string processCanny() {
        cv::Mat test = cv::Mat::zeros(10, 10, CV_8UC1);
        return "OpenCV Mat created! Version: " + std::string(CV_VERSION);
    }
};

// Ваш биндинг — это "мостик" для JavaScript
EMSCRIPTEN_BINDINGS(eco_monitor_module) {
    class_<EcoMonitor>("EcoMonitor")
        .constructor<>()
        .function("processCanny", &EcoMonitor::processCanny);
}
