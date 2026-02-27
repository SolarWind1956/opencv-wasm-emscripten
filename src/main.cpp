#include <opencv2/imgproc.hpp>
#include <emscripten/bind.h>
#include <emscripten/val.h>

using namespace cv;
using namespace emscripten;

class EcoMonitor {
private:
    Mat processedFrame;

public:
    EcoMonitor() {}

    // Основной метод обработки
    // val input — это ссылка на объект JavaScript (например, ImageData или Buffer)
    void processCanny(int inputAddr, int width, int height, double threshold1, double threshold2) {
        // Создаем Mat из сырых данных, переданных из JS по адресу в памяти
        uint8_t* data = reinterpret_cast<uint8_t*>(inputAddr);
        Mat frame(height, width, CV_8UC4, data); // 8-bit, 4 channels (RGBA)
        
        // 1. Переводим в градации серого (Canny работает с одноканальным изображением)
        cvtColor(frame, processedFrame, COLOR_RGBA2GRAY);
        
        // 2. Применяем фильтр Кэнни
        Canny(processedFrame, processedFrame, threshold1, threshold2);
        
        // 3. Возвращаем результат обратно в исходный кадр (RGBA) для отображения
        cvtColor(processedFrame, frame, COLOR_GRAY2RGBA);
    }
};

// --- Тот самый блок-переводчик ---
EMSCRIPTEN_BINDINGS(eco_monitor_module) {
    class_<EcoMonitor>("EcoMonitor")
        .constructor<>()
        .function("processCanny", &EcoMonitor::processCanny);
}

