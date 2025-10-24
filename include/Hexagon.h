#pragma once
#include "Figure.h"
#include <vector>
#include <cmath>

class Hexagon : public Figure {
private:
    std::vector<Point> pts;
public:
    Hexagon();
    Point center() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    bool operator==(const Figure& other) const override;
};
