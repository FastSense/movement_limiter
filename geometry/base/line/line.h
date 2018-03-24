#pragma once

namespace movement_limiter {

class Line {
public:
  Line(const Point& anchor_point, const Vector& direction):
      anchor_point_(anchor_point), direction_(direction) {
    assert(direction.length() > kEpsilon);
  }

  Line(const Point& first_point, const Point& second_point):
      anchor_point(first_point), direction(Vector(second_point) - Vector(first_point)) {
    assert(first_point != second_point); 
  }

  Point anchor_point() const { return anchor_point_; }
  Vector direction() const { return direction_; }

  double a() const { return -direction.y(); }
  double b() const { return direction.x(); }
  double c() const { return anchor_point.x() * (anchor_point.y() + direction.y()) -
      anchor_point.y * (anchor_point.x() + direction.x()); }

  double deviation(const Point& point) const {
    return (a() * point.x() + b() * point.y() + c()) /
        sqrt(a() * a() + b() * b());
  }

  int deviation_sign(const Point& point) const {
    if (deviation(point) > kEpsilon) {
      return 1;
    } else if (deviation(point) < -kEpsilon) {
      return -1;
    } else {
      return 0;
    }
  }

  double rotate(Point rotate_center, double angle) {
    Vector vector_to_rotate = Vector(rotate_center, anchor_point);
    vector_to_rotate.rotate(angle);
    Point new_anchor_point = rotate_center + vector_to_rotate; 

    vector_to_rotate = Vector(rotate_center, anchor_point + direction_);
    vector_to_rotate.rotate(angle);
    Point new_direction = new_anchor_point - (rotate_center + vector_to_rotate);

    anchor_point_ = new_anchor_point;
    direction_ = new_direction;
  }  

private:
  Point anchor_point_;
  Vector direction_;
}
  
}  // namespace movement_limiter
