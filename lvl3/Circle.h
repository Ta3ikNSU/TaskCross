//
// Created by Ta3ik on 12.12.2021.
//

#ifndef TASK_CIRCLE_H
#define TASK_CIRCLE_H

#include <list>
#include <cmath>
#include "Color.h"
#include "Figure.h"

class Circle : public FlatFigure {
private:
    double radius;
    std::pair<double, double> cord;
public:
    Circle(double rad, double x, double y, int r, int g, int b) {
        setRadius(rad);
        setCord(x, y);
        setColor(r, g, b);
    }

    double area() override {
        return radius * radius * M_PI;
    }

    double perimeter() override {
        return 2 * radius * M_PI;
    }

    double getRadius() {
        return radius;
    }

    std::pair<double, double> getCord() {
        return cord;
    }

    void setRadius(double r) {
        radius = r;
    }

    void setCord(double x, double y) {
        cord.first = x;
        cord.second = y;
    }

    void draw(std::pair<double, double> origin, double angle, QPainter &qPainter) override {
        std::pair<double, double> cent = recalcCord(1, cord.first, cord.second, angle);
        qPainter.drawEllipse(cent.first - radius + origin.second,
                             cent.second - radius + origin.second,
                             radius, radius
        );
    }
    std::list<std::string> getListParameters() override{
        std::list<std::string> param;
        param.emplace_back("Move x");
        param.emplace_back("Move y");
        param.emplace_back("Radius");
        param.emplace_back("Color red");
        param.emplace_back("Color green");
        param.emplace_back("Color blue");
        return param;
    }

    void setParam(std::vector<double> list) override{
        this->setCord(cord.first + list[0], cord.second + list[1]);
        this->setRadius(list[2]);
        this->setColor(list[3],list[4],list[5]);
    }

    ~Circle(){}
};

#endif //TASK_CIRCLE_H
