//
// Created by Ta3ik on 12.12.2021.
//

#ifndef UNTITLED2_FLAT_FIGURE_H
#define UNTITLED2_FLAT_FIGURE_H


#include "Color.h"
#include "string"
#include <QPainter>
#include "cereal/archives/json.hpp"

class FlatFigure {
protected:
    Color color;
public:
    Color getColor() const {
        return color;
    }

    void setColor(int r, int g, int b) {
        color.setBlue(b);
        color.setGreen(g);
        color.setRed(r);
    }

    std::pair<double, double> recalcCord(double sign, double x, double y, double angle) {
        return std::pair<double, double>(
                x * cos(angle) - sign * y * sin(angle),
                sign * y * cos(angle) + x * sin(angle)
        );
    }

    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void draw(std::pair<double, double> origin, double angle, QPainter& qPainter) = 0;
    virtual std::list<std::string> getListParameters() = 0;
    virtual void setParam(std::vector<double>)= 0;
};


#endif //UNTITLED2_FLAT_FIGURE_H
