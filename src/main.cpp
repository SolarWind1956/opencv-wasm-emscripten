#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <emscripten/bind.h>
#include <emscripten/val.h>

using namespace emscripten;

class EcoMonitor {
public:
    EcoMonitor() {}

        std::string processFrame(uintptr_t buffer, int width, int height) {
        // 1. Создаем матрицу из входящего RGBA буфера
        cv::Mat frame(height, width, CV_8UC4, reinterpret_cast<unsigned char*>(buffer));
        cv::Mat gray, edges;
        
        // 2. В серый цвет и детектор Кэнни
        cv::cvtColor(frame, gray, cv::COLOR_RGBA2GRAY);
        cv::Canny(gray, edges, 50, 150);

        // 3. МАГИЯ: Превращаем серые края (1 канал) обратно в RGBA (4 канала), 
        // чтобы браузер смог это нарисовать на Canvas
        cv::cvtColor(edges, frame, cv::COLOR_GRAY2RGBA);

        int nonZero = cv::countNonZero(edges);
        return "🚀 EcoMonitor v0.5: Найдено " + std::to_string(nonZero) + " точек контуров.";
    }

};

EMSCRIPTEN_BINDINGS(eco_monitor_module) {
    class_<EcoMonitor>("EcoMonitor")
        .constructor<>()
        .function("processFrame", &EcoMonitor::processFrame);
}
