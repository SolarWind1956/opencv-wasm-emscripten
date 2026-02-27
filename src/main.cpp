#include <emscripten/bind.h>
#include <iostream>

using namespace emscripten;

class EcoMonitor {
public:
    EcoMonitor() {
        std::cout << "EcoMonitor Engine Ready!" << std::endl;
    }

    // Временно просто возвращаем то же самое, чтобы проверить связь
    void processCanny(int inputAddr, int width, int height, double t1, double t2) {
        // Мы вернемся сюда, когда подключим opencv.js отдельно
    }
};

EMSCRIPTEN_BINDINGS(eco_monitor_module) {
    class_<EcoMonitor>("EcoMonitor")
        .constructor<>()
        .function("processCanny", &EcoMonitor::processCanny);
}
