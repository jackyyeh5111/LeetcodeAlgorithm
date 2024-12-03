#include <iostream>
#include <vector>
#include <cmath>

// Define a 3x3 matrix class to represent the model-view-projection matrices
class Matrix3x3 {
public:
    float m[3][3];

    // Constructor to initialize the matrix
    Matrix3x3() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                m[i][j] = 0.0f;
    }

    // Matrix multiplication
    Matrix3x3 operator*(const Matrix3x3& other) const {
        Matrix3x3 result;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    result.m[i][j] += m[i][k] * other.m[k][j];
        return result;
    }

    // Transform a 3D point using this matrix (for MVP transformation)
    std::vector<float> transform(const std::vector<float>& point) const {
        std::vector<float> result(3, 0.0f);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                result[i] += m[i][j] * point[j];
        return result;
    }
};

// Utility function to print a 3D point
void printPoint(const std::vector<float>& point) {
    std::cout << "(" << point[0] << ", " << point[1] << ", " << point[2] << ")\n";
}

// Example 3D point structure
struct Vertex {
    float x, y, z;

    // Constructor to initialize vertex
    Vertex(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

    // Convert to a vector (to work with matrices)
    std::vector<float> toVector() const {
        return {x, y, z};
    }
};

int main() {
    // Define the model, view, and projection matrices

    Matrix3x3 model;    // The model matrix (transformation in object space)
    model.m[0][0] = 1;  model.m[0][1] = 0;  model.m[0][2] = 0;
    model.m[1][0] = 0;  model.m[1][1] = 1;  model.m[1][2] = 0;
    model.m[2][0] = 0;  model.m[2][1] = 0;  model.m[2][2] = 1;

    Matrix3x3 view;     // The view matrix (camera transformation)
    view.m[0][0] = 1;   view.m[0][1] = 0;   view.m[0][2] = 0;
    view.m[1][0] = 0;   view.m[1][1] = 1;   view.m[1][2] = 0;
    view.m[2][0] = 0;   view.m[2][1] = 0;   view.m[2][2] = 1;

    Matrix3x3 projection; // The projection matrix (perspective or orthographic)
    projection.m[0][0] = 1;   projection.m[0][1] = 0;   projection.m[0][2] = 0;
    projection.m[1][0] = 0;   projection.m[1][1] = 1;   projection.m[1][2] = 0;
    projection.m[2][0] = 0;   projection.m[2][1] = 0;   projection.m[2][2] = 1;

    // Example vertex
    Vertex vertex(1.0f, 2.0f, 3.0f);

    // First apply the model transformation (identity in this case)
    std::vector<float> transformedVertex = model.transform(vertex.toVector());

    // Then apply the view transformation (identity in this case)
    transformedVertex = view.transform(transformedVertex);

    // Finally, apply the projection transformation
    transformedVertex = projection.transform(transformedVertex);

    // Print the final transformed 3D point
    std::cout << "Transformed Vertex: ";
    printPoint(transformedVertex);

    return 0;
}
