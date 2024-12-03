#include <iostream>
#include <stdexcept>

using namespace std;

// Function to rotate a 3D point using a rotation matrix (using raw array)
void rotatePoint(const double point[3], const double rotationMatrix[3][3], double rotatedPoint[3]) {
    // Matrix multiplication: rotatedPoint = rotationMatrix * point
    for (int i = 0; i < 3; ++i) {
        rotatedPoint[i] = 0.0;
        for (int j = 0; j < 3; ++j) {
            rotatedPoint[i] += rotationMatrix[i][j] * point[j];
        }
    }
}

int main() {
    // Example point (3D point)
    double point[3] = {1.0, 0.0, 0.0};
    
    // Example rotation matrix (90 degrees about the Z-axis)
    double rotationMatrix[3][3] = {
        {0.0,  1.0, 0.0},
        {1.0,  0.0, 0.0},
        {0.0,  0.0, 1.0}
    };
    
    double rotatedPoint[3];  // Array to store the rotated point
    
    try {
        // Call the rotation function
        rotatePoint(point, rotationMatrix, rotatedPoint);
        
        // Print the rotated point
        cout << "Rotated Point: (" 
             << rotatedPoint[0] << ", " 
             << rotatedPoint[1] << ", " 
             << rotatedPoint[2] << ")" << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    
    return 0;
}
