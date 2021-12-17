#ifndef UNTITLED2_FLAT_FIGURE_H
#define UNTITLED2_FLAT_FIGURE_H


#include "Color.h"
#include "string"
#include <QPainter>
#include "cereal/archives/json.hpp"
#include <cmath>

class FlatFigure {
protected:
    // цвет фигуры
    Color color;
public:
    // функция получения цвета фигуры
    Color getColor() const {
        return color;
    }

    // функция установки цвета фигуры
    void setColor(int r, int g, int b) {
        color.setBlue(b);
        color.setGreen(g);
        color.setRed(r);
    }

    // вычисление площади
    virtual double area() = 0;

    // вычисление периметра
    virtual double perimeter() = 0;

    // сдвиг фигуры
    virtual void move(double x, double y) = 0;

    // отрисовка фигуры
    virtual void draw(std::pair<double, double> origin, double angle, QPainter *qPainter) = 0;

    // функция получения списка названий параметров фигуры
    virtual std::vector<std::string> getListParameters() = 0;

    // функция получения параметров выбранной фигуры с их значениями
    virtual std::vector<std::pair<std::string, double>> getParams() = 0;

    // функция установки новых параметров фигуры
    virtual void replace(std::vector<double>) = 0;

    // функция получения типа фигуры в виде строки
    virtual std::string getType() = 0;

    // функция сериализации фигуры
    virtual std::string serialize() = 0;
};


#endif //UNTITLED2_FLAT_FIGURE_H
