#include <iostream>
#include <vector>
#include <algorithm>

class SparseMatrixCSR {
private:
    std::vector<double> values;       // Non-zero values
    std::vector<int> colIndices;      // Column indices for each value
    std::vector<int> rowPointers;     // Row pointers indicating the start of each row

    int numRows;
    int numCols;

public:
    SparseMatrixCSR(int rows, int cols) : numRows(rows), numCols(cols) {
        rowPointers.resize(rows + 1, 0);
    }

    // Add a non-zero value to the matrix
    void addValue(int row, int col, double value) {
        if (value == 0) return; // Skip zero values

        // Find the position to insert in values and colIndices
        int pos = rowPointers[row];
        while (pos < rowPointers[row + 1] && colIndices[pos] < col) {
            ++pos;
        }

        // Insert the value and column index at the found position
        values.insert(values.begin() + pos, value);
        colIndices.insert(colIndices.begin() + pos, col);

        // Update the row pointers for subsequent rows
        for (int i = row + 1; i < rowPointers.size(); ++i) {
            ++rowPointers[i];
        }
    }

    // Get the value at the given row and column
    double getValue(int row, int col) const {
        for (int i = rowPointers[row]; i < rowPointers[row + 1]; ++i) {
            if (colIndices[i] == col) {
                return values[i];
            }
        }
        return 0.0; // Return zero if the element is not found
    }

    // Display the matrix in CSR format
    void displayCSR() const {
        std::cout << "Values: ";
        for (double v : values) {
            std::cout << v << " ";
        }
        std::cout << "\nColumn Indices: ";
        for (int c : colIndices) {
            std::cout << c << " ";
        }
        std::cout << "\nRow Pointers: ";
        for (int r : rowPointers) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }

    // Display the matrix in dense format for verification
    void displayDense() const {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                std::cout << getValue(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SparseMatrixCSR matrix(4, 5);
    matrix.addValue(0, 1, 3.5);
    matrix.addValue(2, 3, 4.2);
    matrix.addValue(1, 0, -1.1);
    matrix.addValue(3, 4, 2.3);

    std::cout << "CSR Representation:" << std::endl;
    matrix.displayCSR();

    std::cout << "Dense Representation:" << std::endl;
    matrix.displayDense();

    return 0;
}
