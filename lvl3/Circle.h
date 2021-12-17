#ifndef TASK_CIRCLE_H
#define TASK_CIRCLE_H

#include <list>
#include <cmath>
#include <fstream>
#include "Color.h"
#include "Figure.h"

class Circle : public FlatFigure {
private:
    // радиус круга
    double radius;
    // координта центра
    std::pair<double, double> cord;
public:
    // конструктор. принимает радиус, координаты центра, цвет
    Circle(double rad, double x, double y, int r, int g, int b) {
        setRadius(rad);
        setCord(x, y);
        setColor(r, g, b);
    }

    // функция вычисления площади
    double area() override {
        return radius * radius * M_PI;
    }

    // функция вычисления периметра
    double perimeter() override {
        return 2 * radius * M_PI;
    }

    // функция сдвига фигуры относительно начала координат
    void move(double x, double y) override {
        cord.first += x;
        cord.second += y;
    }

    // функция получения радиуса круга
    double getRadius() {
        return radius;
    }

    // функция получения координат центра круга
    std::pair<double, double> getCord() {
        return cord;
    }

    // функция для установки радиуса
    void setRadius(double r) {
        radius = r;
    }

    // функция для установки новых координат центра
    void setCord(double x, double y) {
        cord.first = x;
        cord.second = y;
    }

    // функция отрисовки круга
    void draw(std::pair<double, double> origin, double angle, QPainter *qPainter) override {
        QPen pen;
        pen.setWidth(3);
        pen.setColor(QColor(color.getRed(), color.getGreen(), color.getBlue()));
        qPainter->setPen(pen);
        qPainter->rotate((int) angle % 360);
        qPainter->drawEllipse(cord.first - radius / 2,
                              -cord.second - radius / 2,
                              radius, radius
        );
        qPainter->rotate(-(int) angle % 360);
    }


    // функция получения списка названий параметров круга
    std::vector<std::string> getListParameters() override {
        std::vector<std::string> param;
        param.emplace_back("Radius");
        param.emplace_back("Center x");
        param.emplace_back("Center y");
        param.emplace_back("Color red");
        param.emplace_back("Color green");
        param.emplace_back("Color blue");
        return param;
    }

    // функция получения списка параметров круга с их значениями
    std::vector<std::pair<std::string, double>> getParams() override {
        std::vector<std::pair<std::string, double>> params;
        params.emplace_back("Radius", radius);
        params.emplace_back("Center x", cord.first);
        params.emplace_back("Center y", cord.second);
        params.emplace_back("Color red", color.getRed());
        params.emplace_back("Color green", color.getGreen());
        params.emplace_back("Color blue", color.getBlue());
        return params;
    }

    // функция сериализации круга
    std::string serialize() override {
        std::stringstream out;
        cereal::JSONOutputArchive ar(out);
        ar(cereal::make_nvp("radius", radius),
           cereal::make_nvp("center x", cord.first),
           cereal::make_nvp("center y", cord.second),
           cereal::make_nvp("red", color.getRed()),
           cereal::make_nvp("green", color.getGreen()),
           cereal::make_nvp("blue", color.getBlue())
        );
        return out.str();
    }

    // функция установки новых параметров круга
    void replace(std::vector<double> newParams) override {
        radius = newParams[0];
        cord.first = newParams[1];
        cord.second = newParams[2];
        color.setRed(newParams[3]);
        color.setGreen(newParams[4]);
        color.setBlue(newParams[5]);
    }

    // деструктор
    ~Circle() {}

    // возврат название типа
    std::string getType() override {
        return "Circle";
    }
};

#endif //TASK_CIRCLE_H
