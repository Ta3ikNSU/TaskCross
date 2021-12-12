//
// Created by Ta3ik on 12.12.2021.
//

#ifndef TASK_RECTANGLE_H
#define TASK_RECTANGLE_H

#include <cmath>
#include "Color.h"
#include "Figure.h"

class Rectangle : public FlatFigure {

private:
    Color color;
    std::pair<double, double> from;
    std::pair<double, double> to;
public:
    Rectangle() = delete;

    Rectangle(double x_from, double y_from, double x_to, double y_to,
              int red, int green, int blue) {
        from = std::pair<double, double>(x_from, y_from);
        to = std::pair<double, double>(x_to, y_to);
        color = Color(red, green, blue);
    }

    virtual double area() override {
        double right = std::max(from.first, to.first);
        double left = std::min(from.first, to.first);
        double up = std::max(from.second, to.second);
        double down = std::min(from.second, to.second);
        return (right - left) * (up - down);
    }

    double perimeter() override {
        double right = std::max(from.first, to.first);
        double left = std::min(from.first, to.first);
        double up = std::max(from.second, to.second);
        double down = std::min(from.second, to.second);
        return 2 * ((right - left) + (up - down));
    }

    std::pair<double, double> getFromCordPointLeft() {
        if (from.first < to.first) return from;
        else return to;
    }

    std::pair<double, double> getFromCordPointRight() {
        if (from.first < to.first) return to;
        else return from;
    }

    void setNewCord(double x_from, double y_from, double x_to, double y_to) {
        from.first = x_from;
        from.second = y_from;
        to.first = x_to;
        to.second = y_to;
    }

    template<class Archive>
    void serialize(Archive &ar) {
        ar(cereal::make_nvp("red", color.getRed()),
           cereal::make_nvp("green", color.getGreen()),
           cereal::make_nvp("blue", color.getBlue())
        );
    }


public:
    void draw(std::pair<double, double> origin, double angle, QPainter &qPainter) override {
        double sign = -1.0;
        if (angle > 0) {
            sign = 1;
        }
        qPainter.rotate((int) angle % 360);
        qPainter.fillRect(QRect(from.first, from.second, to.first, to.second),
                          QColor(color.getRed(), color.getGreen(), color.getBlue()));
        qPainter.rotate(-((int) angle % 360));
//        std::pair<double, double> p1 = recalcCord(sign, from.first, from.second, angle);
//        std::pair<double, double> p2 = recalcCord(sign, to.first, from.second, angle);
//        std::pair<double, double> p3 = recalcCord(sign, from.first, to.second, angle);
//        std::pair<double, double> p4 = recalcCord(sign, to.first, to.second, angle);
//        qPainter.drawLine(p1.first + origin.first,
//                          p1.second + origin.second,
//                          p2.first + origin.first,
//                          p2.second + origin.second);
//        qPainter.drawLine(p2.first + origin.first,
//                          p2.second + origin.second,
//                          p3.first + origin.first,
//                          p3.second + origin.second);
//        qPainter.drawLine(p3.first + origin.first,
//                          p3.second + origin.second,
//                          p4.first + origin.first,
//                          p4.second + origin.second);
//        qPainter.drawLine(p4.first + origin.first,
//                          p4.second + origin.second,
//                          p1.first + origin.first,
//                          p1.second + origin.second);
    }

    std::list<std::string> getListParameters() override {
        std::list<std::string> param;
        param.emplace_back("First point x");
        param.emplace_back("First point y");
        param.emplace_back("Second point x");
        param.emplace_back("Second point y");
        param.emplace_back("Color red");
        param.emplace_back("Color green");
        param.emplace_back("Color blue");
        return param;
    }

    void setParam(std::vector<double> list) override {
        this->setNewCord(list[0], list[1], list[2], list[3]);
        this->setColor(list[4], list[5], list[6]);
    }

    ~Rectangle(){}
};


#endif //TASK_RECTANGLE_H
