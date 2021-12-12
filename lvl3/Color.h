//
// Created by Ta3ik on 12.12.2021.
//

#ifndef TASK_COLOR_H
#define TASK_COLOR_H

#include <algorithm>

class Color {
private:
    int red;
    int green;
    int blue;
public:
    Color(int red_value, int green_value, int blue_value) {
        //значения палитры 0..255
        red = std::max(0, std::min(red_value, 255));
        green = std::max(0, std::min(green_value, 255));
        blue = std::max(0, std::min(blue_value, 255));
    }

    Color(){
        red = 255;
        green = 255;
        blue = 255;
    }

    void setGreen(int green_new_value) {
        green = green_new_value;
    }

    void setRed(int red_new_value) {
        red = red_new_value;
    }

    void setBlue(int blue_new_value) {
        blue = blue_new_value;
    }

    int getBlue() {
        return blue;
    }

    int getRed() {
        return red;
    }

    int getGreen() {
        return green;
    }

};


#endif //TASK_COLOR_H
