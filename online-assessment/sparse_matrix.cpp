#include <iostream>
#include <map>

class SparseMatrix {
public:
    // Constructor
    SparseMatrix(int rows, int cols) : rows_(rows), cols_(cols) {}

    // Method to add a non-zero element to the sparse matrix
    void addValue(int row, int col, double value) {
        if (value != 0) {
            data_[{row, col}] = value;
        }
    }

    // Method to get a value from the sparse matrix
    double getValue(int row, int col) const {
        auto it = data_.find({row, col});
        if (it != data_.end()) {
            return it->second;
        }
        return 0.0;
    }

    // Method to perform dot product with another sparse matrix
    double dotProduct(const SparseMatrix& other) const {
        // sanity check
        if (rows_ != other.rows_ || cols_ != other.cols_) {
            throw std::invalid_argument("Matrix dimensions do not match for dot product");
        }

        if (data_.size() > other.data_.size())
            return other.dotProduct(*this);

        double result = 0.0;

        // Iterate through non-zero elements of this matrix
        for (const auto& [coord, value] : data_) {
            int row = coord.first;
            int col = coord.second;
            result += value * other.getValue(row, col);
        }
        return result;
    }

    // Method to display the matrix
    void display() const {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                std::cout << getValue(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int rows_;
    int cols_;
    std::map<std::pair<int, int>, double> data_; // Map to store non-zero values
};

int main() {
    // Create two sparse matrices with the same dimensions
    SparseMatrix mat1(2, 3);
    SparseMatrix mat2(2, 3);

    // Add values to the first matrix
    mat1.addValue(0, 0, 1.0);
    mat1.addValue(0, 2, 2.0);
    mat1.addValue(1, 1, 3.0);

    // Add values to the second matrix
    mat2.addValue(0, 0, 4.0);
    mat2.addValue(0, 2, 5.0);
    mat2.addValue(1, 2, 6.0);

    // Perform dot product
    double result = mat1.dotProduct(mat2);

    // Display the result
    std::cout << "Dot Product Result: " << result << std::endl;

    return 0;
}
