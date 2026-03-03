#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <emscripten/bind.h>
#include <string>

using namespace emscripten;

// --- 1. УРОВЕНЬ АБСТРАКЦИИ ---
// Это "чертеж" для любого будущего процессора
class IProcessor {
public:
    virtual ~IProcessor() {} // Чистим за собой память правильно
    virtual std::string process(cv::Mat& frame) = 0; // Чистая виртуальная функция
};

// --- 2. УРОВЕНЬ РЕАЛИЗАЦИИ ---
// Конкретный алгоритм (Canny)
class CannyProcessor : public IProcessor {
private:
    int lowThreshold = 50;
public:
    std::string 	process(cv::Mat& frame) override 
	{
        cv::Mat gray, edges;
        
        // Знакомая вам логика OpenCV
        cv::cvtColor(frame, gray, cv::COLOR_RGBA2GRAY);
        cv::Canny(gray, edges, lowThreshold, 150);
        
        // Превращаем обратно в RGBA для отрисовки в Canvas
        cv::cvtColor(edges, frame, cv::COLOR_GRAY2RGBA);

        int nonZero = cv::countNonZero(edges);
        return "Canny: Найдено " + std::to_string(nonZero) + " точек.";
    }
};

// --- 3. ВАШ ОСНОВНОЙ КЛАСС (Контейнер) ---
class EcoMonitor {
private:
    IProcessor* processor; // Та самая АГРЕГАЦИЯ из диаграммы (указатель)

public:
    EcoMonitor() {
        // Создаем конкретную реализацию при старте
        processor = new CannyProcessor(); 
    }
    
    ~EcoMonitor() { 
        // Важно: удаляем процессор, когда монитор больше не нужен
        delete processor; 
    }

    std::string processFrame(uintptr_t buffer, int width, int height) {
        // Оборачиваем входящие байты в объект cv::Mat
        cv::Mat frame(height, width, CV_8UC4, reinterpret_cast<unsigned char*>(buffer));
        
        if (processor) {
            // Магия: вызываем метод через интерфейс
            return processor->process(frame);
        }
        return "Ошибка: Процессор не инициализирован";
    }
};

// --- 4. МОСТИК ДЛЯ JAVASCRIPT ---
EMSCRIPTEN_BINDINGS(eco_monitor_module) {
    class_<EcoMonitor>("EcoMonitor")
        .constructor<>()
        .function("processFrame", &EcoMonitor::processFrame);
}
