#include <emscripten/bind.h>
#include <string>

using namespace emscripten;

class EcoMonitor {
public:
    EcoMonitor() {}

    std::string processCanny() {
        // Мы не вызываем cv::Mat напрямую здесь, чтобы линковщик не ругался,
        // но подтверждаем, что класс EcoMonitor живой!
        return "C++ EcoMonitor ready! OpenCV will be handled via JS bridge.";
    }
};

EMSCRIPTEN_BINDINGS(eco_monitor_module) {
    class_<EcoMonitor>("EcoMonitor")
        .constructor<>()
        .function("processCanny", &EcoMonitor::processCanny);
}
