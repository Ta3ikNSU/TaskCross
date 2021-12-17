#ifndef TASK_RECTANGLE_H
#define TASK_RECTANGLE_H

#include <cmath>
#include "Color.h"
#include "Figure.h"

class Rectangle : public FlatFigure {

private:
    // начальная точка прямоугольника
    std::pair<double, double> from;
    // конечная точка прямоуголльника
    std::pair<double, double> to;
public:
    // удаляем конструктор без параметров, чтобы нельзя было создать прямоугольник без координат вершин
    Rectangle() = delete;

    // функция сдвига фигуры относительно начала координат
    void move(double x, double y) override {
        from.first += x;
        from.second -= y;
        to.first += x;
        to.second -= y;
    }

    // конструктор для создания прямоугольника
    Rectangle(double x_from, double y_from, double x_to, double y_to,
              int red, int green, int blue) {
        from = std::pair<double, double>(x_from, y_from);
        to = std::pair<double, double>(x_to, y_to);
        color = Color(red, green, blue);
    }

    // функция вычисления площади
    double area() override {
        double right = std::max(from.first, to.first);
        double left = std::min(from.first, to.first);
        double up = std::max(from.second, to.second);
        double down = std::min(from.second, to.second);
        return (right - left) * (up - down);
    }

    // функция вычисления периметра
    double perimeter() override {
        double right = std::max(from.first, to.first);
        double left = std::min(from.first, to.first);
        double up = std::max(from.second, to.second);
        double down = std::min(from.second, to.second);
        return 2 * ((right - left) + (up - down));
    }

    // получить координаты левой точки
    std::pair<double, double> getFromCordPointLeft() {
        if (from.first < to.first) return from;
        else return to;
    }

    // получить координаты правой точки
    std::pair<double, double> getFromCordPointRight() {
        if (from.first < to.first) return to;
        else return from;
    }

    // установить новые координаты вершин прямоугольника
    void setNewCord(double x_from, double y_from, double x_to, double y_to) {
        from.first = x_from;
        from.second = y_from;
        to.first = x_to;
        to.second = y_to;
    }

    // функция сериализации
    std::string serialize() override {
        std::stringstream out;
        cereal::JSONOutputArchive ar(out);
        ar(cereal::make_nvp("red", color.getRed()),
           cereal::make_nvp("green", color.getGreen()),
           cereal::make_nvp("blue", color.getBlue()),
           cereal::make_nvp("from_x", from.first),
           cereal::make_nvp("from_y", from.second),
           cereal::make_nvp("to_x", to.first),
           cereal::make_nvp("to_y", to.second)
        );
        return out.str();
    }

    // функция отрисовки прямугольника
    void draw(std::pair<double, double> origin, double angle, QPainter *qPainter) override {
        QPen pen;
        pen.setWidth(3);
        pen.setColor(QColor(color.getRed(), color.getGreen(), color.getBlue()));
        qPainter->setPen(pen);
        qPainter->rotate((int) angle % 360);

        qPainter->drawRect(QRect(from.first, from.second, to.first - from.first,
                                 to.second - from.second));
        qPainter->rotate(-((int) angle % 360));

    }

    // функция получения списка параметров прямоугольника
    std::vector<std::string> getListParameters() override {
        std::vector<std::string> param;
        param.emplace_back("First point x");
        param.emplace_back("First point y");
        param.emplace_back("Second point x");
        param.emplace_back("Second point y");
        param.emplace_back("Color red");
        param.emplace_back("Color green");
        param.emplace_back("Color blue");
        return param;
    }

    // функция установки новых параметров прямоугольника
    void replace(std::vector<double> newParams) override {
        to.first = newParams[0];
        to.second = newParams[1];
        from.first = newParams[2];
        from.second = newParams[3];
        color.setRed(newParams[4]);
        color.setGreen(newParams[5]);
        color.setBlue(newParams[6]);
    }


    // функция получения списка параметров прямоугольника с их значениями
    std::vector<std::pair<std::string, double>> getParams() override {
        std::vector<std::pair<std::string, double>> params;
        params.emplace_back("First point x", from.first);
        params.emplace_back("First point y", from.second);
        params.emplace_back("Second point x", to.first);
        params.emplace_back("Second point y", to.second);
        params.emplace_back("Color red", color.getRed());
        params.emplace_back("Color green", color.getGreen());
        params.emplace_back("Color blue", color.getBlue());
        return params;
    }

    // деструктор фигуры
    ~Rectangle() {}

    // возврат название типа
    std::string getType() override {
        return "Rectangle";
    }
};


#endif //TASK_RECTANGLE_H
