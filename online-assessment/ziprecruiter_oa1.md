You are given a rectangular matrix of characters matrix, which represents a 2-dimensional field where each cell contains the following types of cells:

'-' represents an empty cell,
'#' represents an obstacle,
'F' corresponds to a cell of a connected figure.
It is guaranteed that the connected figure exists and its cells, denoted by ('F'), are connected horizontally and/or vertically.

Gravity makes the figure fall toward the bottom of the field, until one of its cells reaches the ground (bottom edge of the matrix), or meets an obstacle. Your task is to return the state of the field after the figure stops falling.

Note: You are not expected to provide the most optimal solution, but a solution with time complexity not worse than O(matrix.length2 · ,matrix[0].length2) will fit within the execution time limit.

Example

For

matrix = [['F', 'F', 'F'],
          ['-', 'F', '-'],
          ['-', 'F', 'F'],
          ['#', 'F', '-'],
          ['F', 'F', '-'],
          ['-', '-', '-'],
          ['-', '-', '#'],
          ['-', '-', '-']]
the output should be

solution(matrix) = [['-', '-', '-'],
                    ['-', '-', '-'],
                    ['F', 'F', 'F'],
                    ['#', 'F', '-'],
                    ['-', 'F', 'F'],
                    ['-', 'F', '-'],
                    ['F', 'F', '#'],
                    ['-', '-', '-']]
Expand to see the example video.

Note: If you are unable to see the video properly, please use this link to access it.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[memory limit] 1 GB

[input] array.array.char matrix

A rectangular matrix representing the field containing the connected figure. It is guaranteed that each cell of the figure will be touching at least one side of another figure cell. It is also guaranteed that matrix contains only the symbols '-', 'F', and '#'.

Guaranteed constraints:
1 ≤ matrix.length ≤ 50,
1 ≤ matrix[i].length ≤ 50,
matrix[i].length = matrix[0].length.

[output] array.array.char

The state of the field after the figure stops falling.