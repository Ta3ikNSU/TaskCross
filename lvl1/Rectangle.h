//
// Created by Ta3ik on 12.12.2021.
//

#ifndef TASK_RECTANGLE_H
#define TASK_RECTANGLE_H

#include <cmath>
#include "Color.h"

class Rectangle {

private:
    Color color;
    std::pair<double, double> from;
    std::pair<double, double> to;
public:
    Rectangle(double x_from, double y_from, double x_to, double y_to,
             int red, int green, int blue){
        from = std::pair<double, double>(x_from, y_from);
        to = std::pair<double, double>(x_to, y_to);
        color = Color(red, green, blue);
    }

    double area(){
        double right = std::max(from.first, to.first);
        double left= std::min(from.first, to.first);
        double up = std::max(from.second, to.second);
        double down = std::min(from.second, to.second);
        return (right - left) * (up-down);
    }

    double perimeter(){
        double right = std::max(from.first, to.first);
        double left= std::min(from.first, to.first);
        double up = std::max(from.second, to.second);
        double down = std::min(from.second, to.second);
        return 2 * ((right - left) +  (up-down));
    }

    Color getColor(){
        return color;
    }

    void setColor(int r, int g, int b){
        color.setBlue(b);
        color.setGreen(g);
        color.setRed(r);
    }

    std::pair<double, double> getFromCordPointLeft(){
        if(from.first < to.first) return from;
        else return to;
    }

    std::pair<double, double> getFromCordPointRight(){
        if(from.first < to.first) return to;
        else return from;
    }

    void setNewCord(double x_from, double y_from, double x_to, double y_to){
        from.first = x_from;
        from.second = y_from;
        to.first = x_to;
        to.second = y_to;
    }
};


#endif //TASK_RECTANGLE_H
