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
    // 1) find bottom-most point as start
    Point start = *std::min_element(points.begin(), points.end(), [](const Point& p1, const Point& p2){
        if (p1.y == p2.y) return p1.x < p2.x;
        return p1.y < p2.y;
    });

    // 2) sort by polar angle based on strat
    sort(points.begin(), points.end(), [start](const Point& p1, const Point& p2){
        double angle1 = atan2(p1.y - start.y, p1.x - start.x);
        double angle2 = atan2(p2.y - start.y, p2.x - start.x);
        if (angle1 == angle2) { // return point that closer to start
            int dist1 = (p1.x - start.x) * (p1.x - start.x) + (p1.y - start.y) * (p1.y - start.y);
            int dist2 = (p2.x - start.x) * (p2.x - start.x) + (p2.y - start.y) * (p2.y - start.y);
            return dist1 < dist2;
        }
        return angle1 < angle2;
    });
    
    // 3) convex hull algo
    for (const auto& pt : points) {
        while(hull.size() >= 2) {
            // check if turning counterclockwise
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
  char heap[] = "hello";
  heap[0] = 'a';

  return 0;
}
