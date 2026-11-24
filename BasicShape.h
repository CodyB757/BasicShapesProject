#ifndef BASICSHAPE_H
#define BASICSHAPE_H

#include <string>

class BasicShape {
private:
    double area;
    std::string name;

protected:
    void setArea(double newArea);

    static std::string checkedNonBlank(const std::string& value, const std::string& fieldName);
    static double checkedFinite(double value, const std::string& fieldName);
    static double checkedPositive(double value, const std::string& fieldName);
    static double checkedFiniteArea(double computedArea);

public:
    BasicShape(const std::string& shapeName);
    virtual ~BasicShape() {}

    double getArea() const;
    std::string getName() const;
    void setName(const std::string& shapeName);

    virtual void calcArea() = 0;
};

#endif
