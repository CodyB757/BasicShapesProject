#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "BasicShape.h"
#include <string>

class Rectangle : public BasicShape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w, const std::string& shapeName = "Rectangle");

    double getLength() const;
    double getWidth() const;

    virtual void setLength(double l);
    virtual void setWidth(double w);

    void calcArea() override;
};

#endif