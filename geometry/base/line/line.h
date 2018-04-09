#pragma once
#include <cassert>
#include "../point/point.h"
#include "../vector/vector.h"

namespace movement_limiter {

class Line {
public:
  Line() = default;
  Line(const Point& anchor_point, const Vector& direction);
  Line(const Point& first_point, const Point& second_point);
  Line(double a, double b, double c);

  Point anchor_point() const { return anchor_point_; }
  Point secondary_point() const { return secondary_point_; }
  Vector direction() const { return direction_; }

  double a() const { return -direction_.y(); }
  double b() const { return direction_.x(); }
  double c() const;
  double angle_coefficient() const;
  double height_from_ox() const;

  double deviation(const Point& point) const;
  int deviation_sign(const Point& point) const;
  void rotate(Point rotate_center, double angle);
  bool at_the_same_semiplane(const Point& a, const Point& b) const;

private:
  Point anchor_point_;
  Point secondary_point_;
  Vector direction_;
};
  
}  // namespace movement_limiter
