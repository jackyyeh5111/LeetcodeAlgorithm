#include <chrono>
#include <iostream>
#include <shared_mutex>
#include <thread>
#include <vector>

using namespace std;
class Matrix33 {
public:
  float m[3][3];
  Matrix33() {
    for (int r = 0; r < 3; r++)
      for (int c = 0; c < 3; c++) 
        m[r][c] = 0.f;
  }

  Matrix33 operator*(const Matrix33& other) {
    Matrix33 result;
    for (int r = 0; r < 3; r++)
      for (int c = 0; c < 3; c++) 
        for (int k = 0; k < 3; k++) 
          result.m[r][c] += m[r][k] * other.m[k][c];
    return result;
  }

  // Transform
  vector<float> transform(const vector<float>& point) {
    vector<float> result(3);
    for (int r = 0; r < 3; r++)
      for (int c = 0; c < 3; c++) 
          result[r] += m[r][c] * point[c];
    return result;
  }
};

// Utility function to print a 3D point
void printPoint(const std::vector<float>& point) {
    std::cout << "(" << point[0] << ", " << point[1] << ", " << point[2] << ")\n";
}

int main() {
  Matrix33 model;    // The model matrix (transformation in object space)
  model.m[0][0] = 0;  model.m[0][1] = 1;  model.m[0][2] = 0;
  model.m[1][0] = 1;  model.m[1][1] = 0;  model.m[1][2] = 0;
  model.m[2][0] = 0;  model.m[2][1] = 0;  model.m[2][2] = 1;

  // Example vertex
  vector<float> vec{1.0f, 2.0f, 3.0f};

  // First apply the model transformation (identity in this case)
  std::vector<float> transformedVertex = model.transform(vec);

  // Print the final transformed 3D point
  std::cout << "Transformed Vertex: ";
  printPoint(transformedVertex);

  return 0;
}
