#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <emscripten/bind.h>
#include <emscripten/val.h>

using namespace emscripten;

class EcoMonitor {
public:
    EcoMonitor() {}

    // Функция принимает данные кадра, ширину и высоту
    std::string processFrame(uintptr_t buffer, int width, int height) {
        // 1. Создаем матрицу из сырых данных, пришедших из JS
        cv::Mat frame(height, width, CV_8UC4, reinterpret_cast<unsigned char*>(buffer));
        
        // 2. Переводим в оттенки серого (для детектора контуров)
        cv::Mat gray, edges;
        cv::cvtColor(frame, gray, cv::COLOR_RGBA2GRAY);
        
        // 3. ПРИМЕНЯЕМ ДЕТЕКТОР КЭННИ (Canny Edge Detector)
        // Ищем границы мидий: пороги 50 и 150
        cv::Canny(gray, edges, 50, 150);
        
        // 4. Считаем количество "белых" пикселей (активность границ)
        int nonZero = cv::countNonZero(edges);
        
        return "📢 EcoMonitor: Обнаружено " + std::to_string(nonZero) + " точек контуров мидий.";
    }
};

EMSCRIPTEN_BINDINGS(eco_monitor_module) {
    class_<EcoMonitor>("EcoMonitor")
        .constructor<>()
        .function("processFrame", &EcoMonitor::processFrame);
}
