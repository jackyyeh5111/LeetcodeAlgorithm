/* 
    Similar to quad tree / octree!
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if all elements in a region are the same
char checkRegion(const vector<vector<char>>& image, int start_r, int start_c, int size) {
    char first = image[start_r][start_c];
    for (int r = start_r; r < start_r + size; r++) {
        for (int c = start_c; c < start_c + size; c++) {
            if (first != image[r][c])
                return 'M';
        }
    }
    return first;
}

// Recursive function to divide the image and build the result array
void processImage(const vector<vector<char>>& image, int r, int c, int size, vector<char>& result) {
    char val = checkRegion(image, r, c, size);
    result.push_back(val);
    if (size == 1) return;

    // recursive check
    if (val == 'M') {
        int new_size = size / 2;
        processImage(image, r, c, new_size, result);
        processImage(image, r, c + new_size, new_size, result);
        processImage(image, r + new_size, c + new_size, new_size, result);
        processImage(image, r + new_size, c, new_size, result);
    }
    
}

// Example usage
int main() {
    vector<vector<char>> image = {
        {'T', 'T', 'F', 'F'},
        {'T', 'T', 'F', 'F'},
        {'T', 'T', 'T', 'F'},
        {'T', 'T', 'T', 'F'}
    };

    vector<char> result;
    processImage(image, 0, 0, image.size(), result);

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
