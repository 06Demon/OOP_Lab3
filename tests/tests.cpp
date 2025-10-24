#include <gtest/gtest.h>
#include "../include/Rhombus.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"

TEST(RhombusTest, AreaAndCenter) {
    Rhombus r({0, 0}, {1, 1}, {2, 0}, {1, -1});
    EXPECT_NEAR(static_cast<double>(r), 2.0, 1e-6);
    auto c = r.center();
    EXPECT_DOUBLE_EQ(c.x, 1.0);
    EXPECT_DOUBLE_EQ(c.y, 0.0);
}

TEST(PentagonTest, AreaCalculation) {
    Pentagon p;
    std::istringstream in("0 0 1 0 1.5 1 0.5 2 -0.5 1");
    in >> p;
    EXPECT_NEAR(static_cast<double>(p), 2.5, 1e-1);
}

TEST(HexagonTest, Equality) {
    std::istringstream in1("0 0 1 0 2 1 2 2 1 3 0 2");
    std::istringstream in2("0 0 1 0 2 1 2 2 1 3 0 2");
    Hexagon h1, h2;
    in1 >> h1;
    in2 >> h2;
    EXPECT_TRUE(h1 == h2);
}

TEST(HexagonTest, CenterCalculation) {
    std::istringstream in("0 0 1 0 2 1 2 2 1 3 0 2");
    Hexagon h;
    in >> h;
    auto c = h.center();
    EXPECT_NEAR(c.x, 1.0, 1e-6);
    EXPECT_NEAR(c.y, 1.333, 1e-3);
}
