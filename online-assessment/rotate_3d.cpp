#include <iostream>
#include <vector>

using namespace std;

// Function to rotate a 3D point using a rotation matrix
vector<double> rotatePoint(const vector<double>& point, const vector<vector<double>>& rotationMatrix) {
    // Ensure the point is 3D and the rotation matrix is 3x3
    if (point.size() != 3 || rotationMatrix.size() != 3 || rotationMatrix[0].size() != 3) {
        throw invalid_argument("Point must be 3D and rotation matrix must be 3x3.");
    }
    
    vector<double> rotatedPoint(3, 0.0);
    
    // Matrix multiplication: rotatedPoint = rotationMatrix * point
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            rotatedPoint[i] += rotationMatrix[i][j] * point[j];
        }
    }
    
    return rotatedPoint;
}

int main() {
    // Example point
    vector<double> point = {1.0, 0.0, 0.0};
    
    // Example rotation matrix (90 degrees about the Z-axis)
    vector<vector<double>> rotationMatrix = {
        {0.0, -1.0, 0.0},
        {1.0,  0.0, 0.0},
        {0.0,  0.0, 1.0}
    };
    
    try {
        vector<double> rotatedPoint = rotatePoint(point, rotationMatrix);
        
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
