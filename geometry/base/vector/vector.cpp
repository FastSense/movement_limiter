#include "vector.h"
#include "../constants/constants.h"
#include <cassert>
#include <cmath>

namespace movement_limiter {

void Vector::rotate(double angle) {
  double new_x = x_ * std::cos(angle) - y_ * std::sin(angle);
  double new_y = x_ * std::sin(angle) + y_ * std::cos(angle);
  x_ = new_x;
  y_ = new_y;
}

void Vector::set_length(double new_length) {
  assert(abs(length()) > kEpsilon);
  auto old_length = length();
  x_ *= new_length / old_length;
  y_ *= new_length / old_length;
}

void Vector::operator=(const Point& point) {
  x_ = point.x();
  y_ = point.y();
}

Vector Vector::operator*(double scalar) const {
  return Vector(x_ * scalar, y_ * scalar);
}

}  // namespace movement_limiter
