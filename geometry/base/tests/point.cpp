#include "../point/point.h"
#include "../constants/constants.h"
#include <gtest/gtest.h>
#include <cmath>

using namespace movement_limiter;

TEST(Point, EqualityOfTwoWithDifferenceLowerEpsilon) {
  ASSERT_TRUE(Point(0, kEpsilon / 2.0) == Point(0, 0));
  ASSERT_TRUE(Point(kEpsilon / 2.0, 0) == Point(0, 0));
  ASSERT_TRUE(Point(kEpsilon / 2.0, kEpsilon / 2.0) == Point(0, 0));
}

TEST(Point, UnequalityOfTwoWithDifferenceUpperEpsilon) {
  ASSERT_TRUE(Point(-kEpsilon, kEpsilon) != Point(kEpsilon, -kEpsilon));
  ASSERT_TRUE(Point(kEpsilon / 2.0, kEpsilon / 2.0) != Point(-kEpsilon / 2.0, -kEpsilon / 2.0));
}

TEST(Point, SumOfTwoPoints) {
  ASSERT_EQ(Point(5, 5) + Point(10, -100), Point(15, -95));
}

TEST(Point, SubOfTwoPoints) {
  ASSERT_EQ(Point(100, 75) - Point(23, 105), Point(77, -30));
}

TEST(Point, DitanceToAnotherPoint) {
  ASSERT_EQ(Point(0, 0).distance_to(Point(1, 1)), std::sqrt(2));
  ASSERT_EQ(Point(100, 50).distance_to(Point(40, 256)), 2.0 * std::sqrt(11509));
}