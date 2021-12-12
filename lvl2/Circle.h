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
    Circle(double rad, double x, double y, int r, int g, int b){
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

    double getRadius(){
        return radius;
    }

    std::pair<double, double> getCord(){
        return cord;
    }

    void setRadius(double r){
        radius = r;
    }

    void setCord(double x, double y){
        cord.first = x;
        cord.second = y;
    }
};

#endif //TASK_CIRCLE_H
