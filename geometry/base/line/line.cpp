#include "line.h"
#include <iostream>
#include <cassert>

namespace movement_limiter {

Line::Line(const Point& anchor_point, const Vector& direction):
    anchor_point_(anchor_point), secondary_point_(anchor_point + direction), direction_(direction) {
  assert(direction.length() > kEpsilon);
}

Line::Line(const Point& first_point, const Point& second_point):
    anchor_point_(first_point), secondary_point_(second_point),
    direction_(second_point - first_point) {
  assert(first_point != second_point);
}

Line::Line(double a, double b, double c) {
  assert(std::abs(a) > kEpsilon || std::abs(b) > kEpsilon);
  if (std::abs(a) < kEpsilon) {
    anchor_point_ = Point(0, -c / b);
    secondary_point_ = Point(5, -c / b);
  } else if (std::abs(b) < kEpsilon) {
    anchor_point_ = Point(-c / a, 0);
    secondary_point_ = Point(-c / a, 5);
  } else {
    anchor_point_ = Point(0, -c / b);
    secondary_point_ = Point(5, (-c - 5.0 * a) / b);
  }
  direction_ = secondary_point_ - anchor_point_;
}

double Line::c() const {
  return anchor_point_.x() * secondary_point_.y() - anchor_point_.y() * secondary_point_.x();
}

double Line::deviation(const Point& point) const {
  return (a() * point.x() + b() * point.y() + c()) / sqrt(a() * a() + b() * b());
}

int Line::deviation_sign(const Point& point) const {
  if (deviation(point) > kEpsilon) {
    return 1;
  } else if (deviation(point) < -kEpsilon) {
    return -1;
  } else {
    return 0;
  }
}

void Line::rotate(Point rotate_center, double angle) {
  Vector vector_to_rotate(rotate_center, anchor_point_);
  vector_to_rotate.rotate(angle);
  anchor_point_ = rotate_center + vector_to_rotate;

  vector_to_rotate = Vector(secondary_point_);
  vector_to_rotate.rotate(angle);
  secondary_point_ = rotate_center + vector_to_rotate;

  direction_ = secondary_point_ - anchor_point_;
}

double Line::angle_coefficient() const {
  if (secondary_point_.x() == anchor_point_.x()) {
    return kInfinity;
  }
  return (secondary_point_.y() - anchor_point_.y()) / (secondary_point_.x() - anchor_point_.x());
}

double Line::height_from_ox() const {
  if (secondary_point_.x() == anchor_point_.x()) {
    return kInfinity;
  }
  return -anchor_point_.x() * (secondary_point_.y() - anchor_point_.y()) /
      (secondary_point_.x() - anchor_point_.x()) + anchor_point_.y();
}

bool Line::at_the_same_semiplane(const Point& a, const Point& b) const {
  return deviation_sign(a) == deviation_sign(b);
}

}  // namespace movement_limiter
