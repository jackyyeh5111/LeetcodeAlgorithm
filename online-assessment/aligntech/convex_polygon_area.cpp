#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
struct Point {
  int x, y;

  // Friend declaration for overloading <<
  // Friend declaration for overloading <<
  friend std::ostream& operator<<(std::ostream& os, const Point& pt) {
    os << "(x: " << pt.x << ", y: " << pt.y << ")";
    return os;
  }
};

int crossProd(const Point& p1, const Point& p2, const Point& p3) {
  // vec1: (p2.x - p1.x, p2.y - p1.y)
  // vec2: (p3.x - p2.x, p3.y - p2.y)
  return (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
}

int computeArea(std::vector<Point>& points) {
  // 1) specify bottom-most point as start
  Point start = *std::min_element(points.begin(), points.end(),
                                  [](const Point& p1, const Point& p2) {
                                    if (p1.y == p2.y) return p1.x < p2.x;
                                    return p1.y < p2.y;
                                  });

  // 2) sort by polar angle (couterclockwise)
  std::sort(points.begin(), points.end(),
            [start](const Point& p1, const Point& p2) {
              double angle1 = std::atan2(p1.y - start.y, p1.x - start.x);
              double angle2 = std::atan2(p2.y - start.y, p2.x - start.x);
              if (angle1 == angle2) {
                int dist1 = (p1.x - start.x) * (p1.x - start.x) +
                            (p1.y - start.y) * (p1.y - start.y);
                int dist2 = (p2.x - start.x) * (p2.x - start.x) +
                            (p2.y - start.y) * (p2.y - start.y);
                return dist1 < dist2;
              }
              return angle1 < angle2;
            });

  // debug
  for (int i = 0; i < points.size(); i++) {
    std::cout << "i: " << i << "=> " << points[i] << '\n';
  }

  // 3) triangulation and sum every triangle area
  Point curr = points[1];
  int area = 0;
  for (int i = 2; i < points.size(); i++) {
    area += crossProd(start, curr, points[i]) / 2;  // remember to divide by 2!
    curr = points[i];
  }
  return area;
}

int main() {
  std::vector<Point> points = {{0, 2}, {0, 0}, {2, 0}, {2, 2}};
  int area = computeArea(points);
  std::cout << "area: " << area << '\n';

  return 0;
}
