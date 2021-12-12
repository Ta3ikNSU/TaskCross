//
// Created by Ta3ik on 12.12.2021.
//

#ifndef UNTITLED2_FLAT_FIGURE_H
#define UNTITLED2_FLAT_FIGURE_H


#include "Color.h"

class FlatFigure {
protected:
    Color color;

public:
    Color getColor(){
        return color;
    }

    void setColor(int r, int g, int b){
        color.setBlue(b);
        color.setGreen(g);
        color.setRed(r);
    }

    virtual double area() = 0;
    virtual double perimeter() = 0;
};


#endif //UNTITLED2_FLAT_FIGURE_H
