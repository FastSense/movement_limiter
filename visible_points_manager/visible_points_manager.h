#pragma once
#include "../geometry/base/point/point.h"
#include "../geometry/base/vector/vector.h"
#include "../geometry/base/line/line.h"
#include <vector>

namespace movement_limiter {

class VisiblePointsManager {
public:
  VisiblePointsManager() = default;
  VisiblePointsManager(const Point& position, const Vector& sight_direction,
      const std::vector<Point>& points);

  Point nearest_visible_point() const;

  void add_point(const Point& point);
  void set_position(const Point& position);
  void set_sight_direction(const Vector& sight_direction);
  bool has_visible_point() const { return !visible_points_.empty(); }

private:
  void update_visible_points();
  
  std::vector<Point> points_;
  std::vector<Point> visible_points_;
  Point position_;
  Vector sight_direction_;

  Line left_sight_border_;
  Line right_sight_border_;
  Line back_sight_border_;
};
  
}  // namespace movement_limiter
