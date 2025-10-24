#pragma once
#include "Figure.h"
#include <vector>
#include <cmath>

class Pentagon : public Figure {
private:
    std::vector<Point> pts;
public:
    Pentagon();
    Point center() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    bool operator==(const Figure& other) const override;
};
