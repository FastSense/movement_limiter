#include "point.h"
#include "../constants/constants.h"
#include <cmath>
#include <iostream>

namespace movement_limiter {

double Point::distance_to(const Point& point) const {
  return std::hypot(this->x_ - point.x_, this->y_ - point.y_);
}

bool Point::operator==(const Point& rhs) const {
  return distance_to(rhs) < kEpsilon;
}

bool Point::operator!=(const Point& rhs) const {
  return !(*this == rhs);
}

Point Point::operator+(const Point& rhs) const {
  return Point(this->x_ + rhs.x_, this->y_ + rhs.y_);
}

Point Point::operator-(const Point& rhs) const {
  return Point(this->x_ - rhs.x_, this->y_ - rhs.y_);
}

}  // namespace movement_limiter
