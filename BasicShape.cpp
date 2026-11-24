#include "BasicShape.h"
#include <stdexcept>
#include <cctype>
#include <cmath>

std::string BasicShape::checkedNonBlank(const std::string& value, const std::string& fieldName) {
    bool hasChar = false;
    for (char c : value) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            hasChar = true;
            break;
        }
    }
    if (!hasChar) {
        throw std::invalid_argument(fieldName + " cannot be blank.");
    }
    return value;
}

double BasicShape::checkedFinite(double value, const std::string& fieldName) {
    if (!std::isfinite(value)) {
        throw std::invalid_argument(fieldName + " must be a finite number.");
    }
    return value;
}

double BasicShape::checkedPositive(double value, const std::string& fieldName) {
    if (!std::isfinite(value) || value <= 0.0) {
        throw std::invalid_argument(fieldName + " must be finite and greater than 0.");
    }
    return value;
}

double BasicShape::checkedFiniteArea(double computedArea) {
    if (!std::isfinite(computedArea)) {
        throw std::invalid_argument("Calculated area overflows finite limits.");
    }
    return computedArea;
}

BasicShape::BasicShape(const std::string& shapeName)
    : area(0.0), name(checkedNonBlank(shapeName, "Shape name")) {
}

void BasicShape::setArea(double newArea) {
    area = checkedFiniteArea(newArea);
}

double BasicShape::getArea() const {
    return area;
}

std::string BasicShape::getName() const {
    return name;
}

void BasicShape::setName(const std::string& shapeName) {
    name = checkedNonBlank(shapeName, "Shape name");
}