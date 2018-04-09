#pragma once
#include "../point/point.h"
#include <cmath>

namespace movement_limiter {

class Vector : public Point {
public:
  Vector() = default;
  Vector(double x, double y):
      Point(x, y) {}

  explicit Vector(const Point& point):
    Point(point) {}

  Vector(const Point& a, const Point& b):
    Point(b - a) {}

  double length() const { return distance_to(Point(0, 0)); }

  void rotate(double angle);
  void set_length(double length);
  void operator=(const Point& point);
  Vector operator*(double scalar) const;
};
  
}  // namespace movement_limiter
