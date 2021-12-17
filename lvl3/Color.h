#ifndef TASK_COLOR_H
#define TASK_COLOR_H

#include <algorithm>
#include <cmath>

class Color {
private:
    // значения по каждому цвету из RGB
    int red;
    int green;
    int blue;
public:
    // конструктор, задающий конкретное значение
    Color(int red_value, int green_value, int blue_value) {
        //значения палитры 0..255
        red = std::max(0, std::min(red_value, 255));
        green = std::max(0, std::min(green_value, 255));
        blue = std::max(0, std::min(blue_value, 255));
    }

    // конструктор без параметров, устанавливает цвет по умолчанию
    Color() {
        red = 255;
        green = 255;
        blue = 255;
    }

    // установить значения по полю green
    void setGreen(int green_new_value) {
        green = green_new_value;
    }

    // установить значения по полю red
    void setRed(int red_new_value) {
        red = red_new_value;
    }

    // установить значения по полю blue
    void setBlue(int blue_new_value) {
        blue = blue_new_value;
    }

    // получить значение по полю blue
    int getBlue() {
        return blue;
    }

    // получить значение по полю red
    int getRed() {
        return red;
    }

    // получить значение по полю green
    int getGreen() {
        return green;
    }

};


#endif //TASK_COLOR_H
