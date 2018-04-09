#pragma once
#include "../geometry/base/point/point.h"
#include "../geometry/base/vector/vector.h"
#include "../geometry/base/line/line.h"
#include "../logger/logger.h"
#include <vector>

namespace movement_limiter {

class VisiblePointsManager : Logger {
public:
  VisiblePointsManager(double copter_width):
      VisiblePointsManager(Point(0, 0), Vector(0, 1), copter_width, {}) {}
  VisiblePointsManager(const Point& position, const Vector& sight_direction,
      double copter_width, const std::vector<Point>& points);

  Point nearest_visible_point() const;

  void add_point(const Point& point);
  void set_position(const Point& position);
  void set_sight_direction(const Vector& sight_direction);
  bool has_visible_point() const { return !visible_points_.empty(); }

private:
  bool is_visible(const Point& point) const;

  void update_manager_state();
  void update_visible_points();
  void update_sight_borders();

  Point position_;
  Vector sight_direction_;
  double copter_width_;
  std::vector<Line> sight_borders_;
  
  std::vector<Point> points_;
  std::vector<Point> visible_points_;
};
  
}  // namespace movement_limiter
