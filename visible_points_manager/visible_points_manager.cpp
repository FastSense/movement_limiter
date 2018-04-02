#include "visible_points_manager.h"
#include "geometry/base/point/point.h"

namespace movement_limiter {

VisiblePointsManager::VisiblePointsManager(const Point& position, const Vector& sight_direction,
    const std::vector<Point>& points):
    position_(position), sight_direction_(sight_direction), points_(points) {}

void VisiblePointsManager::add_point(const Point& point) {
  points_.push_back(point);
}

void VisiblePointsManager::set_position(const Point& position) {
  position_ = position;
}

void VisiblePointsManager::set_sight_direction(const Vector& sight_direction) {
  sight_direction_ = sight_direction;
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

void VisiblePointsManager::update_visible_points() {
  visible_points_.clear();
  auto point_in_sight = position_ + sight_direction_;
  for (const auto& point : points_) {
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

}  // namespace movement_limiter
