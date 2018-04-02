#include "../line/line.h"
#include <gtest/gtest.h>
#include <cmath>

using namespace movement_limiter;

TEST(Line, CoefficientsByTwoPoints) {
  Line line(Point(-3, 5), Point(7, 11));
}

TEST(Line, AngleCoefficient) {
  Line line(Point(-3, 5), Point(7, 11));
  ASSERT_EQ(line.angle_coefficient(), 0.6);
  ASSERT_EQ(line.height_from_ox(), 6.8);
}

TEST(Line, Deviation) {
  Line line(7, 5, 10);
  ASSERT_EQ(line.deviation(Point(4, 6)), 34.0 * std::sqrt(74) / 37.0);

  line = Line(0, 5, 10);
  ASSERT_EQ(line.deviation(Point(4, 6)), 8);

  line = Line(7, 0, 10);
  ASSERT_EQ(line.deviation(Point(4, 6)), -38.0 / 7.0);

  line = Line(Point(0, 0), Point(0, 10));
  ASSERT_EQ(line.deviation(Point(5, 0)), -5);
  ASSERT_EQ(line.deviation(Point(-5, 0)), 5);
  ASSERT_EQ(line.deviation(Point(0, 0)), 0);

  line = Line(Point(0, 0), Point(10, 0));
  ASSERT_EQ(line.deviation(Point(0, 5)), 5);
  ASSERT_EQ(line.deviation(Point(0, -5)), -5);
}


