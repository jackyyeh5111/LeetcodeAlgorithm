#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>  // For atan2 and sqrt
using namespace std;
struct Point {
    int x, y;
};

double rad2deg(double rad) {
    return rad * 180 / M_PI;
}
int main() {
    vector<Point> points {{-1, -1},
{1, -1},
{0, 0},
{3, 0},
{1, 1},
{2, 2},
{0, 3},
{-1, 1}};

    for (const auto& pt : points) {
        std::cout << pt.x << ", " << pt.y << ": " << rad2deg(std::atan2(pt.y, pt.x)) << '\n';
    }
    // std::cout << "std::atan2(1, -1): " << rad2deg(std::atan2(1, -1) )<< '\n';
    // std::cout << "std::atan2(1, 1): " << rad2deg(std::atan2(1, 1) )<< '\n';
    // std::cout << "std::atan2(-1, 1): " << rad2deg(std::atan2(-1, 1)) << '\n';
    return 0;
}