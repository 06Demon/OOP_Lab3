#include "../include/Hexagon.h"

Hexagon::Hexagon() : pts(6) {}

Point Hexagon::center() const {
    double cx = 0, cy = 0;
    for (auto& p : pts) { cx += p.x; cy += p.y; }
    return {cx / 6, cy / 6};
}

Hexagon::operator double() const {
    double s = 0;
    for (int i = 0; i < 6; ++i) {
        int j = (i + 1) % 6;
        s += pts[i].x * pts[j].y - pts[j].x * pts[i].y;
    }
    return std::fabs(s) / 2.0;
}

void Hexagon::print(std::ostream& os) const {
    os << "Шестиугольник: ";
    for (auto& p : pts) os << "(" << p.x << "," << p.y << ") ";
}

void Hexagon::read(std::istream& is) {
    for (auto& p : pts) is >> p.x >> p.y;
}

bool Hexagon::operator==(const Figure& other) const {
    const auto* o = dynamic_cast<const Hexagon*>(&other);
    if (!o) return false;
    for (int i = 0; i < 6; ++i)
        if (pts[i].x != o->pts[i].x || pts[i].y != o->pts[i].y)
            return false;
    return true;
}
