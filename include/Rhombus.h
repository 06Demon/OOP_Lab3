#pragma once
#include "Figure.h"
#include <cmath>

class Rhombus : public Figure {
private:
    Point a, b, c, d;
public:
    Rhombus() = default;
    Rhombus(Point a_, Point b_, Point c_, Point d_);

    Point center() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    bool operator==(const Figure& other) const override;
};
