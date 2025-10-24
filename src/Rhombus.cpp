#include "../include/Rhombus.h"

Rhombus::Rhombus(Point a_, Point b_, Point c_, Point d_) : a(a_), b(b_), c(c_), d(d_) {}

Point Rhombus::center() const {
    return {(a.x + c.x) / 2, (a.y + c.y) / 2};
}

Rhombus::operator double() const {
    double d1 = std::hypot(a.x - c.x, a.y - c.y);
    double d2 = std::hypot(b.x - d.x, b.y - d.y);
    return d1 * d2 / 2;
}

void Rhombus::print(std::ostream& os) const {
    os << "Ромб: A(" << a.x << "," << a.y << ") "
       << "B(" << b.x << "," << b.y << ") "
       << "C(" << c.x << "," << c.y << ") "
       << "D(" << d.x << "," << d.y << ")";
}

void Rhombus::read(std::istream& is) {
    is >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
}

bool Rhombus::operator==(const Figure& other) const {
    const auto* o = dynamic_cast<const Rhombus*>(&other);
    if (!o) return false;
    return a.x == o->a.x && a.y == o->a.y &&
           b.x == o->b.x && b.y == o->b.y &&
           c.x == o->c.x && c.y == o->c.y &&
           d.x == o->d.x && d.y == o->d.y;
}
