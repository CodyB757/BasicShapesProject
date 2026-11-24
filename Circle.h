#ifndef CIRCLE_H
#define CIRCLE_H

#include "BasicShape.h"
#include <string>

class Circle : public BasicShape {
private:
    double xCenter;
    double yCenter;
    double radius;

public:
    Circle(double x, double y, double r, const std::string& shapeName = "Circle");

    double getXCenter() const;
    double getYCenter() const;
    double getRadius() const;

    void setXCenter(double x);
    void setYCenter(double y);
    void setRadius(double r);

    void calcArea() override;
};

#endif