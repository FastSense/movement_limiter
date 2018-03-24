#pragma once

namespace movement_limiter {

class VisiblePointsManager {
public:
  VisiblePointsManager(const Point& position, const Vector& sight_direction,
      const std::vector<Points>& points):
          position_(position), sight_direction_(sight_direction), points_(points) {}

  void add_point(const Point& point) {
    points_.push_back(point);
  }

  void set_position(const Point& position) {
    position_ = position;
  }

  void set_sight_direction(const Vector& sight_direction) {
    sight_direction_ = sight_direction;
  }

  bool has_visible_point() const { return !visible_points.empty(); }

  Point nearest_visible_point() const {
    assert(has_visible_point());
    auto result = visible_points_.front();
    for (const auto& visible_point : visible_points_) {
      if (Vector(position_, visible_point).length() < Vector(position_, result).length()) {
        result = visible_point;
      }
    }
    return result;
  }

private:
  void update_visible_points() {
    visible_points_.clear();
    auto point_in_sight = position_ + sight_direction_;
    for (const auto& point : points) {
      if (left_sight_border_.deviation_sign(point_in_sight) !=
          left_sight_border_.deviation_sign(point)) {
        continue;    
      }
      if (right_sight_border_.deviation_sign(point_in_sight) != 
          right_sight_border_.deviation_sign(point)) {
        continue;      
      }
      if (back_sight_border_.deviation_sign(point_in_sight) != 
          back_sight_border_.deviation_sign(point)) {
        continue;      
      }
      visible_points_.push_back(point);
    }
  }  
  
  std::vector<Point> points_;
  Point position_;
  Vector sight_direction_;

  Line left_sight_border_;
  Line right_sight_border_;
  Line back_sight_border_;
}
  
}  // namespace movement_limiter
