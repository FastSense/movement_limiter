#pragma once

namespace movement_limiter {

class Point {
public:
  Point():
      x_(0), y_(0) {}

  Point(double x, double y):
      x_(x), y_(y) {}

  double x() const { return x_; }
  double y() const { return y_; }

  bool operator==(const Vector& rhs) {
    std::abs(this->x_ - rhs.x_) + std::abs(this->y_ - rhs.y_) < kEpsilon;
  }

  bool operator!=(const Vector& rhs) {
    std::abs(this->x_ - rhs.x_) + std::abs(this->y_ - rhs.y_) >= kEpsilon;
  }

  void operator+(const Vector& rhs) {
    this->x_ += rhs.x_;
    this->y_ += rhs.y_;
  }

  void operator-(const Vector& rhs) {
    this->x_ -= rhs.x_; 
    this->y_ -= rhs.y_; 
  }
  
private:
  double x_;
  double y_;
}
  
}  // namespace movement_limiter
