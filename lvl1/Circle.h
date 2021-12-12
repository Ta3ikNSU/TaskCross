//
// Created by Ta3ik on 12.12.2021.
//

#ifndef TASK_CIRCLE_H
#define TASK_CIRCLE_H

#include <list>
#include <cmath>
#include "Color.h"

class Circle {
private:
    double radius;
    std::pair<double, double> cord;
    Color color;
public:
    Circle(double rad, double x, double y, int r, int g, int b){
        setRadius(rad);
        setCord(x, y);
        setColor(r, g, b);
    }

    double area() {
        return radius * radius * M_PI;
    }

    double perimeter() {
        return 2 * radius * M_PI;
    }

    Color getColor(){
        return color;
    }

    double getRadius(){
        return radius;
    }

    std::pair<double, double> getCord(){
        return cord;
    }

    void setColor(int r, int g, int b){
        color.setBlue(b);
        color.setGreen(g);
        color.setRed(r);
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
