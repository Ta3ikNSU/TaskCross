#ifndef UNTITLED2_VECTORDOCUMENT_H
#define UNTITLED2_VECTORDOCUMENT_H

#include <list>

#include "Figure.h"

class VectorDocument {
private:
    std::vector<FlatFigure*> elements;
    std::pair<double, double> origin;
    double angle;
public:
    VectorDocument() {
        origin = std::pair<int, int>(450, 400);
        angle = 0;
    }

    // сдвиг всех фигур относительно начала координат
    void move(double x, double y){
        for (auto & element : elements) {
            element->move(x, y);
        }
    }

    // получить список всех фигур
    const std::vector<FlatFigure*> &getElements() {
        return elements;
    }

    // получить список параметров круга с их значениями
    std::vector<std::string> getParam(int index){
        int i = 0;
        auto it = elements.begin();
        while( i < index){
         it++; i++;
        }
        return it.operator*()->getListParameters();
    }

    // добавить новую фигуру
    void addElement(FlatFigure* figure) {
        elements.push_back(figure);
    }

    // получить точку начала координат
    const std::pair<double, double> &getOrigin() const {
        return origin;
    }

    // установить точку начала координат
    void setOrigin(const std::pair<double, double> &origin) {
        VectorDocument::origin = origin;
    }

    // получить текущий угол поворота
    double getAngle() const {
        return angle;
    }

    // установить угол поворота
    void setAngle(double angle) {
        VectorDocument::angle = angle;
    }

    // функция отрисовки всех фигур
    void draw(QPainter* qPainter) {
        qPainter->translate(QPoint(origin.first, origin.second));
        QPen pen;
        pen.setColor(Qt::gray);
        qPainter->setPen(pen);
        qPainter->drawLine(-1000,0,1000,0);
        qPainter->drawLine(0,-800,0,800);
        for (auto & element : elements) {
            if(element == nullptr) continue;
            element->draw(origin, angle, qPainter);
        }
    }

    // получить список параметров фигуры по индексу
    std::vector <std::pair<std::string, double>> getParamsValue(int index){
        return elements[index]->getParams();
    }

    // удалить элемент из списка
    void removeElement(int index) {
        elements[index] = nullptr;
    }
};


#endif //UNTITLED2_VECTORDOCUMENT_H
