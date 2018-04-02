#pragma once
#include "../constants/constants.h"
#include <cmath>

namespace movement_limiter {

class Point {
public:
  Point():
      x_(0), y_(0) {}

  Point(double x, double y):
      x_(x), y_(y) {}

  double x() const { return x_; }
  double y() const { return y_; }
  double distance_to(const Point& point) const;

  bool operator==(const Point& rhs) const;
  bool operator!=(const Point& rhs) const;
  Point operator+(const Point& rhs) const;
  Point operator-(const Point& rhs) const;

protected:
  double x_;
  double y_;
};
  
}  // namespace movement_limiter
