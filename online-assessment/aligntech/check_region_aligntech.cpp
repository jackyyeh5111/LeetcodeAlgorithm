/* 
    Similar to octree!
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if all elements in a region are the same
char checkRegion(const vector<vector<char>>& image, int x, int y, int size) {
    char first = image[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (image[i][j] != first) return 'M'; // Mixed values
        }
    }
    return first; // All values are the same
}

// Recursive function to divide the image and build the result array
void divideImage(const vector<vector<char>>& image, int x, int y, int size, vector<char>& result) {
    char regionValue = checkRegion(image, x, y, size);
    result.push_back(regionValue);

    if (regionValue == 'M' && size > 1) {
        int newSize = size / 2;
        // Divide into 4 quadrants (clockwise order: top-left, top-right, bottom-right, bottom-left)
        divideImage(image, x, y, newSize, result);                    // Top-left
        divideImage(image, x, y + newSize, newSize, result);          // Top-right
        divideImage(image, x + newSize, y + newSize, newSize, result); // Bottom-right
        divideImage(image, x + newSize, y, newSize, result);          // Bottom-left
    }
}

// Main function to process the image
vector<char> processImage(const vector<vector<char>>& image) {
    vector<char> result;
    int n = image.size();
    divideImage(image, 0, 0, n, result);
    return result;
}

// Example usage
int main() {
    vector<vector<char>> image = {
        {'T', 'T', 'F', 'F'},
        {'T', 'T', 'F', 'F'},
        {'T', 'T', 'T', 'F'},
        {'T', 'T', 'T', 'F'}
    };

    vector<char> result = processImage(image);

    int n_row = image.size();
    int n_col = image[0].size();
    for (int r = 0; r < n_row; r++) {
        for (int c = 0; c < n_col; c++) {
            std::cout << image[r][c] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    // Print result
    for (char c : result) {
        printf("%c ", c);
    }
    std::cout << '\n';
    return 0;
}
