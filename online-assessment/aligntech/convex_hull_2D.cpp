#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Point {
  int x, y;
};

/*
    // A utility function to find the orientation of three points
    // Returns:
    // 0 -> p1, p2, p3 are collinear
    // 1 -> Counterclockwise
    // 2 -> Clockweise

    Idea is to use slope!!
    ref: https://www.geeksforgeeks.org/orientation-3-ordered-points/
 */
int orientation(const Point& p1, const Point& p2, const Point& p3) {
  // vec1: (p2.x - p1.x, p2.y - p1.y)
  // vec2: (p3.x - p2.x, p3.y - p2.y)
  // do cross product to check orientation
  int crossProd = (p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
  if (crossProd == 0) return 0;
  else if (crossProd > 0) return 1; // counterclockwise
  else return 2; // clockwise
}

/* 
  Function to find the convex hull of a set of points
  Clarification:
      1. Have to consider if number of point < 3? 
      2. What is all points are collinear?
      3. Is possible points vec got duplicate point?
 */
void convexHull(std::vector<Point>& points, std::vector<Point>& hull) {
  // 1) find the bottom-most point as start point
  auto comp = [](const Point& p1, const Point& p2) {
    return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
  };
  Point start = *std::min_element(points.begin(), points.end(), comp);

  // 2) sort by polar angle based on start point
  std::sort(points.begin(), points.end(), [start](const Point& p1, const Point& p2) {
    double angle1 = std::atan2(p1.y - start.y, p1.x - start.x);
    double angle2 = std::atan2(p2.y - start.y, p2.x - start.x);
    if (angle1 == angle2) {
      // euclidean distance
      int dist1 = (p1.x - start.x) * (p1.x - start.x) + (p1.y - start.y) * (p1.y - start.y);
      int dist2 = (p2.x - start.x) * (p2.x - start.x) + (p2.y - start.y) * (p2.y - start.y);
      return dist1 < dist2;
    }
    return angle1 < angle2;
  });

  // 3) convex hull algo
  for (const auto& pt : points) {
    while(hull.size() >= 2) {
      // next point turn couterclockwise
      int size = hull.size();
      if (orientation(hull[size - 2], hull[size - 1], pt) == 1)
        break;
      hull.pop_back();
    }
    hull.push_back(pt);
  }
}

// Helper function to print the convex hull points
void printHull(const std::vector<Point>& hull) {
  for (const auto& point : hull) {
    std::cout << "(" << point.x << ", " << point.y << ")\n";
  }
}

int main() {
  std::vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                               {0, 0}, {1, 2}, {3, 1}, {3, 3}};

  std::vector<Point> hull;
  convexHull(points, hull);

  std::cout << "The points in the convex hull are:\n";
  printHull(hull);

  return 0;
}
