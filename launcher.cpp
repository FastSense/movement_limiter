#include "visible_points_manager/visible_points_manager.h"
#include "logger/logger.h"
#include <iostream>

using namespace std;
using namespace movement_limiter;

void print_nearest_visible_point(const VisiblePointsManager& points_manager) {
  if (points_manager.has_visible_point()) {
    std::clog << "nearest visible point: " << points_manager.nearest_visible_point().x() << " "
        << points_manager.nearest_visible_point().y() << std::endl;
  }
}

int main() {
  VisiblePointsManager points_manager(2 * sqrt(2));
  points_manager.set_position(Point(0, 0));
  points_manager.set_sight_direction(Vector(1, 1));
  points_manager.add_point(Point(-1, -1));
  print_nearest_visible_point(points_manager);
  points_manager.add_point(Point(2, 2));
  print_nearest_visible_point(points_manager);
  points_manager.add_point(Point(1, 1));
  print_nearest_visible_point(points_manager);
  points_manager.add_point(Point(0, 1));
  print_nearest_visible_point(points_manager);
  return 0;
}
