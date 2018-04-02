#pragma once
#include "vector.h"

namespace movement_limiter {

void Vector::rotate(double angle) {
  double new_x = x_ * std::cos(angle) - y_ * std::sin(angle);
  double new_y = x_ * std::sin(angle) + y_ * std::cos(angle);
  x_ = new_x;
  y_ = new_y;
}

void Vector::operator=(const Point& point) {
  x_ = point.x();
  y_ = point.y();
}

}  // namespace movement_limiter
