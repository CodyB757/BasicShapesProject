#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include "BasicShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

using namespace std;

bool approxEqual(double a, double b, double tol = 1e-6) {
    return std::fabs(a - b) < tol;
}

int main() {
    cout << fixed << setprecision(4);
    cout << "=== 1. CONSTRUCTION & POLYMORPHIC ARRAY ===\n\n";

    Circle c1(0.0, 0.0, 3.0, "Small Circle");
    Circle c2(2.0, -4.0, 10.0, "Large Circle");
    Rectangle r1(4.0, 5.0, "Office Floor");
    Rectangle r2(8.5, 10.0, "Living Room");
    Square sq(4.0, "Patio Square");

    const int NUM_SHAPES = 5;
    BasicShape* shapes[NUM_SHAPES] = { &c1, &c2, &r1, &r2, &sq };

    for (int i = 0; i < NUM_SHAPES; ++i) {
        shapes[i]->calcArea();
        cout << shapes[i]->getName() << " -> Area: " << shapes[i]->getArea() << '\n';
    }

    cout << "\n=== 2. CIRCLE SETTERS & AREA CONSISTENCY ===\n\n";
    c1.setXCenter(15.0);
    c1.setYCenter(-8.0);
    cout << "After center move (15, -8) -> Area unchanged: " << c1.getArea()
        << " (Expected: 28.2743)\n";

    c1.setRadius(5.0);
    cout << "After radius = 5.0 -> New Area: " << c1.getArea()
        << " (Expected: 78.5398)\n";

    cout << "\n=== 3. RECTANGLE SETTERS ===\n\n";
    r1.setLength(6.0);
    cout << "After length = 6.0 -> Area: " << r1.getArea() << " (Expected: 30.0000)\n";
    r1.setWidth(2.5);
    cout << "After width = 2.5  -> Area: " << r1.getArea() << " (Expected: 15.0000)\n";

    cout << "\n=== 4. SQUARE SETTERS & RECTANGLE* / RECTANGLE& OVERRIDES ===\n\n";
    sq.setSide(6.0);
    cout << "After sq.setSide(6.0) -> Side: " << sq.getSide()
        << ", L: " << sq.getLength() << ", W: " << sq.getWidth()
        << ", Area: " << sq.getArea() << '\n';

    Rectangle* rectPtr = &sq;
    rectPtr->setLength(5.0);
    cout << "Via Rectangle* setLength(5.0) -> Side: " << sq.getSide()
        << ", L: " << sq.getLength() << ", W: " << sq.getWidth()
        << ", Area: " << sq.getArea() << '\n';

    Rectangle& rectRef = sq;
    rectRef.setWidth(7.0);
    cout << "Via Rectangle& setWidth(7.0)  -> Side: " << sq.getSide()
        << ", L: " << sq.getLength() << ", W: " << sq.getWidth()
        << ", Area: " << sq.getArea() << '\n';

    cout << "\n=== 5. INVALID INPUT & INVARIANT PROTECTION ===\n\n";
    try {
        c1.setRadius(-2.0);
    }
    catch (const invalid_argument& e) {
        cout << "Rejected negative radius: " << e.what()
            << " | Radius stayed: " << c1.getRadius()
            << ", Area stayed: " << c1.getArea() << '\n';
    }

    try {
        r1.setWidth(0.0);
    }
    catch (const invalid_argument& e) {
        cout << "Rejected zero width: " << e.what()
            << " | Width stayed: " << r1.getWidth()
            << ", Area stayed: " << r1.getArea() << '\n';
    }

    try {
        sq.setName("   ");
    }
    catch (const invalid_argument& e) {
        cout << "Rejected blank name: " << e.what()
            << " | Name stayed: " << sq.getName() << '\n';
    }

    try {
        Square badSq(-4.0);
    }
    catch (const invalid_argument& e) {
        cout << "Rejected negative Square constructor: " << e.what() << '\n';
    }

    cout << "\nTolerance check (c1 area == 78.539816): "
        << (approxEqual(c1.getArea(), 78.5398163397) ? "PASS" : "FAIL") << '\n';

    return 0;
}