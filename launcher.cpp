#include "visible_points_manager/visible_points_manager.h"
#include "logger/logger.h"
#include <iostream>

using namespace std;
using namespace movement_limiter;

int main() {
  VisiblePointsManager point_manager(2 * sqrt(2));
  point_manager.set_position(Point(0, 0));
  point_manager.set_sight_direction(Vector(1, 1));
  point_manager.add_point(Point(-1, -1));
  point_manager.add_point(Point(2, 2));
  std::clog << "visible point: " << point_manager.nearest_visible_point().x() << " "
            << point_manager.nearest_visible_point().y() << std::endl;
  point_manager.add_point(Point(1, 1));
  std::clog << "visible point: " << point_manager.nearest_visible_point().x() << " "
            << point_manager.nearest_visible_point().y() << std::endl;
  point_manager.add_point(Point(0, 1));
  std::clog << "visible point: " << point_manager.nearest_visible_point().x() << " "
            << point_manager.nearest_visible_point().y() << std::endl;
  return 0;
}
