#include "Rectangle.h"

Rectangle::Rectangle(double l, double w, const std::string& shapeName)
    : BasicShape(shapeName),
    length(checkedPositive(l, "Length")),
    width(checkedPositive(w, "Width")) {
    calcArea();
}

double Rectangle::getLength() const { return length; }
double Rectangle::getWidth() const { return width; }

void Rectangle::setLength(double l) {
    double validLength = checkedPositive(l, "Length");
    double newArea = checkedFiniteArea(validLength * width);
    length = validLength;
    setArea(newArea);
}

void Rectangle::setWidth(double w) {
    double validWidth = checkedPositive(w, "Width");
    double newArea = checkedFiniteArea(length * validWidth);
    width = validWidth;
    setArea(newArea);
}

void Rectangle::calcArea() {
    setArea(checkedFiniteArea(length * width));
}