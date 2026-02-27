#include "opencv2/imgproc.hpp" 
#include <emscripten/bind.h>
#include <iostream>

using namespace cv;
using namespace emscripten;

class EcoMonitor {
private:
    Mat processedFrame;

public:
    EcoMonitor() {
        // Здесь можно инициализировать лог или пред-выделить память
        std::cout << "EcoMonitor Engine Initialized" << std::endl;
    }

    void processCanny(int inputAddr, int width, int height, double threshold1, double threshold2) {
        // Создаем "вид" (View) на память JS без копирования
        uint8_t* data = reinterpret_cast<uint8_t*>(inputAddr);
        Mat frame(height, width, CV_8UC4, data); 
        
        // Преобразование в ЧБ и поиск границ
        //cvtColor(frame, processedFrame, COLOR_RGBA2GRAY);
        //Canny(processedFrame, processedFrame, threshold1, threshold2);
        
        // Возвращаем результат в исходный RGBA поток
        //cvtColor(processedFrame, frame, COLOR_GRAY2RGBA);
    }
};

// Блок, который делает класс доступным в браузере
EMSCRIPTEN_BINDINGS(eco_monitor_module) {
    class_<EcoMonitor>("EcoMonitor")
        .constructor<>()
        .function("processCanny", &EcoMonitor::processCanny);
}
