#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Hough Transform function
vector<pair<int, int>> houghTransform(const vector<vector<int>>& binaryImage, int thetaBins, int rhoBins) {
    int rows = binaryImage.size();
    int cols = binaryImage[0].size();

    // Maximum possible rho value
    int maxDist = static_cast<int>(sqrt(rows * rows + cols * cols));
    vector<vector<int>> accumulator(2 * maxDist + 1, vector<int>(thetaBins, 0));

    // Theta step size
    double dTheta = M_PI / thetaBins;

    // Fill the accumulator
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            if (binaryImage[x][y] == 1) {  // Edge pixel
                for (int thetaIndex = 0; thetaIndex < thetaBins; ++thetaIndex) {
                    double theta = thetaIndex * dTheta;
                    int rho = static_cast<int>(x * cos(theta) + y * sin(theta)) + maxDist;
                    accumulator[rho][thetaIndex]++;
                }
            }
        }
    }

    // Extract peaks (lines) from the accumulator
    vector<pair<int, int>> detectedLines; // (rho, thetaIndex)
    int threshold = 100; // Minimum number of votes to consider a line
    for (int rho = 0; rho < 2 * maxDist + 1; ++rho) {
        for (int thetaIndex = 0; thetaIndex < thetaBins; ++thetaIndex) {
            if (accumulator[rho][thetaIndex] > threshold) {
                detectedLines.emplace_back(rho - maxDist, thetaIndex);
            }
        }
    }

    return detectedLines;
}

int main() {
    // Example binary image (1 = edge pixel, 0 = background)
    vector<vector<int>> binaryImage = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
    };

    int thetaBins = 180;  // Number of theta bins
    int rhoBins = 100;    // Number of rho bins

    // Perform Hough Transform
    vector<pair<int, int>> lines = houghTransform(binaryImage, thetaBins, rhoBins);

    // Print the detected lines in (rho, theta) format
    cout << "Detected lines:" << endl;
    for (const auto& line : lines) {
        cout << "Rho: " << line.first << ", Theta Index: " << line.second << endl;
    }

    return 0;
}
