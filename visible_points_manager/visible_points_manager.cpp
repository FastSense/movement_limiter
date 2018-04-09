#include "visible_points_manager.h"
#include "geometry/base/point/point.h"
#include <iostream>

namespace movement_limiter {

namespace {

std::vector<Line> build_sight_borders(const Point& position, Vector sight_direction, double copter_width) {
  if (sight_direction.length() < kEpsilon) {
    return {};
  }
  Vector left_width_point = Vector(position + sight_direction); 
  left_width_point.rotate(kPi / 2.0);
  left_width_point.set_length(copter_width / 2.0);
  Vector right_width_point = Vector(position + sight_direction);
  right_width_point.rotate(-kPi / 2.0);
  right_width_point.set_length(copter_width / 2.0);

  std::vector<Line> sight_borders;
  sight_borders.emplace_back(Point(left_width_point), sight_direction);
  sight_borders.emplace_back(Point(right_width_point), sight_direction);
  sight_borders.emplace_back(Point(left_width_point), Point(right_width_point));
  return sight_borders;
}

}  // namespace

VisiblePointsManager::VisiblePointsManager(const Point& position, const Vector& sight_direction,
    double copter_width, const std::vector<Point>& points):
    Logger("visible_point_manager"), position_(position), sight_direction_(sight_direction),
    copter_width_(copter_width), points_(points) {
  assert(copter_width > kEpsilon);
  LOG("called constructor with copter parameters: position: " <<
      "x: " << position.x() << " y: " << position.y() << 
      " sight_direction: " << 
      "x: " << sight_direction.x() << " y: " << sight_direction.y() << 
      " copter_width: " << copter_width << 
      " points count: " << points.size())
  update_manager_state();
}

void VisiblePointsManager::add_point(const Point& point) {
  LOG("add new point: x: " << point.x() << " y: " << point.y());
  points_.push_back(point);
  if (is_visible(point)) {
    LOG("added point is visible");
    visible_points_.push_back(point);
  }
}

void VisiblePointsManager::set_position(const Point& position) {
  LOG("set_position: x: " << position.x() << " y: " << position.y());
  position_ = position;
  update_manager_state();
}

void VisiblePointsManager::set_sight_direction(const Vector& sight_direction) {
  sight_direction_ = sight_direction;
  update_manager_state();
}

Point VisiblePointsManager::nearest_visible_point() const {
  assert(has_visible_point());
  auto result = visible_points_.front();
  for (const auto& visible_point : visible_points_) {
    if (Vector(position_, visible_point).length() < Vector(position_, result).length()) {
      result = visible_point;
    }
  }
  return result;
}

bool VisiblePointsManager::is_visible(const Point& point) const {
  bool result = true;
  auto point_in_sight = position_ + sight_direction_;
  for (const auto& sight_border : sight_borders_) {
    if (!sight_border.at_the_same_semiplane(point_in_sight, point)) {
      result = false;
    }
  }
  return result;
}

void VisiblePointsManager::update_visible_points() {
  visible_points_.clear();
  for (const auto& point : points_) {
    if (is_visible(point)) {
      visible_points_.push_back(point);
    }
  }
}

void VisiblePointsManager::update_manager_state() {
  update_sight_borders();
  update_visible_points();
}

void VisiblePointsManager::update_sight_borders() {
  sight_borders_ = build_sight_borders(position_, sight_direction_, copter_width_);
}

}  // namespace movement_limiter
