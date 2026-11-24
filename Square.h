#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"
#include <string>

class Square : public Rectangle {
private:
    double side;

public:
    Square(double s, const std::string& shapeName = "Square");

    double getSide() const;
    void setSide(double s);

    void setLength(double l) override;
    void setWidth(double w) override;
};

#endif