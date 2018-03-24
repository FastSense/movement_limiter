#pragma once

namespace movement_limiter {

class Vector : public Point {
public:
  using Point::Point;

  double length() const {
    return std::hypot(x_, y_); 
  }

  void rotate(double angle) const {
    double new_x = x_ * std::cos(angle) - y_ * std::sin(angle);
    double new_y = x_ * std::sin(angle) - y_ * std::cos(angle);
    x_ = new_x;
    y_ = new_y;
  }
}
  
}  // namespace movement_limiter
