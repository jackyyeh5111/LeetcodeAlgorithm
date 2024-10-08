# implement average pooling forward path
# input image: (H, W) 2D
# kernel: k
# stride: 1
# padding: 0

""" 1 2 1.     1.5 1.5
1 2 1  =>  1.5.1.5
4 5 1

1 2 1 1 2 1 4 5 1

1 2
1 2

2 1
2 1

1, 2, 3, 1, 2, 3, ....
[s, e]
 """
import numpy as np
kernel = np.ones((k, k))

output = np.zeros((H - k + 1, W - k + 1))
for row in range(H - k + 1):
    for col in range(W - k + 1):
        val = np.dot(image[row:row+kernel, col:col+kernel], kernel)
        val /= k*k
        output[row][col] = val

# run time O(HW * k^2)


import numpy as np

""" 
    Corner sum
"""
# Step 1: Create a Summed-Area Table (Integral Image)
def create_summed_area_table(matrix):
    n, m = matrix.shape
    sat = np.zeros((n, m), dtype=np.int32)
    
    # Initialize the first element
    sat[0, 0] = matrix[0, 0]
    
    # Fill the first row
    for j in range(1, m):
        sat[0, j] = sat[0, j - 1] + matrix[0, j]
    
    # Fill the first column
    for i in range(1, n):
        sat[i, 0] = sat[i - 1, 0] + matrix[i, 0]
    
    # Fill the rest of the summed-area table
    for i in range(1, n):
        for j in range(1, m):
            sat[i, j] = matrix[i, j] + sat[i - 1, j] + sat[i, j - 1] - sat[i - 1, j - 1]
    
    return sat

# Step 2: Compute the sum of a sub-region using the corner sum technique
def get_subregion_sum(sat, x1, y1, x2, y2):
    total = sat[x2, y2]
    if x1 > 0:
        total -= sat[x1 - 1, y2]
    if y1 > 0:
        total -= sat[x2, y1 - 1]
    if x1 > 0 and y1 > 0:
        total += sat[x1 - 1, y1 - 1]
    return total

# Step 3: Perform average pooling
def average_pooling(matrix, pool_size):
    n, m = matrix.shape
    pooled_matrix = np.zeros((n // pool_size, m // pool_size))
    
    # Create the summed-area table
    sat = create_summed_area_table(matrix)
    
    # Compute the sum for each pooling window and calculate the average
    for i in range(0, n, pool_size):
        for j in range(0, m, pool_size):
            x1, y1 = i, j
            x2, y2 = min(i + pool_size - 1, n - 1), min(j + pool_size - 1, m - 1)
            region_sum = get_subregion_sum(sat, x1, y1, x2, y2)
            num_elements = (x2 - x1 + 1) * (y2 - y1 + 1)
            pooled_matrix[i // pool_size, j // pool_size] = region_sum / num_elements
    
    return pooled_matrix

# Example usage
matrix = np.array([[1, 2, 3, 4],
                   [5, 6, 7, 8],
                   [9, 10, 11, 12],
                   [13, 14, 15, 16]])

pool_size = 2
pooled_matrix = average_pooling(matrix, pool_size)
print(pooled_matrix)
