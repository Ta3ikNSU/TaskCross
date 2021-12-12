//
// Created by Ta3ik on 12.12.2021.
//

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
        origin = std::pair<int, int>(500, 400);
        angle = 0;
    }

    const std::vector<FlatFigure*> &getElements() {
        return elements;
    }

    std::list<std::string> getParam(int index){
        int i = 0;
        auto it = elements.begin();
        while( i < index){
         it++; i++;
        }
        return it.operator*()->getListParameters();
    }

    void setParam(int index, std::vector<double> params){
        int i = 0;
        auto it = elements.begin();
        while( i < index){
            it++; i++;
        }
        it.operator*()->setParam(params);
    }

    void addElement(FlatFigure* figure){
        elements.push_back(figure);
    }

    const std::pair<double, double> &getOrigin() const {
        return origin;
    }

    void setOrigin(const std::pair<double, double> &origin) {
        VectorDocument::origin = origin;
    }

    double getAngle() const {
        return angle;
    }

    void setAngle(double angle) {
        VectorDocument::angle = angle;
    }
    // https://doc.qt.io/qt-5/qtwidgets-painting-painterpaths-example.html

    void draw(QPainter& qPainter) {
        for (auto & element : elements) {
            element->draw(origin, angle, qPainter);
        }
    }

};


#endif //UNTITLED2_VECTORDOCUMENT_H
