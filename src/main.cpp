#include <opencv2/core.hpp>
#include <emscripten/bind.h>
#include <string>

using namespace emscripten;

class EcoMonitor {
public:
    EcoMonitor() {}

    std::string processCanny() {
        // Создаем реальную матрицу OpenCV!
        cv::Mat frame = cv::Mat::zeros(480, 640, CV_8UC1);
        
        std::string info = "OpenCV Mat: " + std::to_string(frame.cols) + "x" + std::to_string(frame.rows);
        return "📢 C++ (WASM) сообщает: " + info + " (Matrix initialized!)";
    }
};

EMSCRIPTEN_BINDINGS(eco_monitor_module) {
    class_<EcoMonitor>("EcoMonitor")
        .constructor<>()
        .function("processCanny", &EcoMonitor::processCanny);
}

