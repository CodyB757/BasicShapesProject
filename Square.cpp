#include "Square.h"

Square::Square(double s, const std::string& shapeName)
    : Rectangle(s, s, shapeName),
    side(checkedPositive(s, "Side")) {
}

double Square::getSide() const {
    return side;
}

void Square::setSide(double s) {
    double validSide = checkedPositive(s, "Side");
    checkedFiniteArea(validSide * validSide);
    Rectangle::setLength(validSide);
    Rectangle::setWidth(validSide);
    side = validSide;
}

void Square::setLength(double l) {
    setSide(l);
}

void Square::setWidth(double w) {
    setSide(w);
}