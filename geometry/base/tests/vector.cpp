#include "../vector/vector.h"
#include <gtest/gtest.h>
#include <cmath>

using namespace movement_limiter;

TEST(Vector, Length) {
  ASSERT_EQ(Vector(1, 1).length(), std::sqrt(2));
  ASSERT_EQ(Vector(0, 0).length(), 0);
  ASSERT_EQ(Vector(-5, -10).length(), 5 * std::sqrt(5));
}

TEST(Vector, Rotate) {
  Vector vector(5, 7);
  vector.rotate(kPi / 2.0);
  ASSERT_EQ(vector, Vector(-7, 5));

  vector = Vector(1, 3);
  vector.rotate(kPi / 6.0);
  ASSERT_EQ(vector,
      Vector(-3.0 / 2.0 + std::sqrt(3) / 2.0, 1.0 / 2.0 + (3.0 * std::sqrt(3)) / (2.0)));

  vector = Vector(11, 9);
  vector.rotate(-kPi / 3.0);
  ASSERT_EQ(vector,
      Vector(11.0 / 2.0 + (9.0 * std::sqrt(3)) / 2.0, 9.0 / 2.0 - (11.0 * std::sqrt(3)) / (2.0)));
}

TEST(Vector, MultiplicationToScalar) {
  ASSERT_EQ(Vector(5, 7) * 13, Vector(65, 91));
  ASSERT_EQ(Vector(0, 10) * 10, Vector(0, 100));
  ASSERT_EQ(Vector(10, 0) * 10, Vector(100, 0));
  ASSERT_EQ(Vector(-10, 13) * (-0.5), Vector(5, -6.5));
}

TEST(Vector, SetLength) {
  Vector vector(2, 6);
  vector.set_length(sqrt(10));
  ASSERT_EQ(vector, Vector(1, 3));
}
