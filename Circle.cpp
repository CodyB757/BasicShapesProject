#include "Circle.h"

namespace {
    const double PI = 3.14159265358979323846;
}

Circle::Circle(double x, double y, double r, const std::string& shapeName)
    : BasicShape(shapeName),
    xCenter(checkedFinite(x, "X center")),
    yCenter(checkedFinite(y, "Y center")),
    radius(checkedPositive(r, "Radius")) {
    calcArea();
}

double Circle::getXCenter() const { return xCenter; }
double Circle::getYCenter() const { return yCenter; }
double Circle::getRadius() const { return radius; }

void Circle::setXCenter(double x) {
    xCenter = checkedFinite(x, "X center");
}

void Circle::setYCenter(double y) {
    yCenter = checkedFinite(y, "Y center");
}

void Circle::setRadius(double r) {
    double validRadius = checkedPositive(r, "Radius");
    double newArea = checkedFiniteArea(PI * validRadius * validRadius);
    radius = validRadius;
    setArea(newArea);
}

void Circle::calcArea() {
    setArea(checkedFiniteArea(PI * radius * radius));
}