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
    int lowThreshold 	= 80;
	int highThreshold 	= 150;
public:
    std::string process(cv::Mat& frame) override {

        cv::Mat gray, blurred, edges, kernel;
        
        // 1. Подготовка (из RGBA в Серый)
        cv::cvtColor(frame, gray, cv::COLOR_RGBA2GRAY);
         
        // 2. Убираем шум
        //	cv::GaussianBlur(gray, blurred, cv::Size(9, 9), 0);
		// 2. Убираем шум (Медианный фильтр вместо Гауссова)
		cv::medianBlur(gray, blurred, 7); // Число должно быть нечетным
		 
        // 3. Детектор границ
        cv::Canny(blurred, edges, lowThreshold, highThreshold);

		// 1. Ищем линии (отрезки)
		std::vector<cv::Vec4i> lines;
		// Очень низкие пороги: 
		// 20 - порог пересечений, 10 - мин. длина, 20 - макс. разрыв между точками
		cv::HoughLinesP(edges, lines, 1, CV_PI/180, 20, 10, 20);

		for (size_t i = 0; i < lines.size(); i++) {
    		cv::Vec4i l = lines[i];
    		// Рисуем ЯРКО-ЗЕЛЕНЫМ (0, 255, 0) и толщиной 5, чтобы точно заметить
    		cv::line	(	frame
						,	cv::Point(l[0], l[1]), cv::Point(l[2], l[3])
						, 	cv::Scalar(0, 255, 0, 255), 5
						, 	cv::LINE_AA
						);
		}
		// 1. Увеличиваем ядро, чтобы "склеить" разрозненные линии в объекты
		kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(11, 11));

		// 2. Операция "Закрытие" (уберет дырки внутри мидий и соединит линии)
		cv::morphologyEx(edges, edges, cv::MORPH_CLOSE, kernel);

		// 3. Операция "Открытие" (уберет мелкий песок и шум в левом нижнем углу)
		cv::morphologyEx(edges, edges, cv::MORPH_OPEN, kernel);

        // 5. Поиск объектов
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        // 6. Отрисовка: Сначала делаем фон цветным, чтобы видеть зеленые линии
        // (Опционально: можно оставить frame как есть, если хотим рисовать по оригиналу)
        // cv::cvtColor(gray, frame, cv::COLOR_GRAY2RGBA); 
   
		int count = 0;
        for (size_t i = 0; i < contours.size(); i++) {
            double area = cv::contourArea(contours[i]);
			// 	Ищем только крупные объекты (раковины)
            if (area > 500) { 
                // Рисуем зеленый контур (RGBA: 0, 255, 0, 255) толщиной 3 пикселя
                cv::drawContours(frame, contours, (int)i, cv::Scalar(0, 255, 0, 255), 3);
                count++;
            }
        }

        int nonZero = cv::countNonZero(edges);
        
        // ВАЖНО для Emscripten: освобождаем временные матрицы
        gray.release(); 
        blurred.release();
        edges.release();
        kernel.release();

        return "Мидий найдено: " + std::to_string(count) + " | Точек: " + std::to_string(nonZero);
    }
};
// --- 3. ОСНОВНОЙ КЛАСС (Контейнер) ---
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

    std::string processFrame(uintptr_t buffer, int width, int height) 
	{
        // Оборачиваем входящие байты в объект cv::Mat
        cv::Mat frame(height, width, CV_8UC4, reinterpret_cast<unsigned char*>(buffer));
        
        if (processor) {
            // Магия: вызываем метод через интерфейс
            return processor->process(frame);
        }
        return "Ошибка: Процессор не инициализирован";
    }
};

// --- МОСТИК ДЛЯ JAVASCRIPT ---
EMSCRIPTEN_BINDINGS(eco_monitor_module) {
    class_<EcoMonitor>("EcoMonitor")
        .constructor<>()
        .function("processFrame", &EcoMonitor::processFrame);
}
