/*
https://leetcode.com/problems/rotate-image/
*/

/*
Intuition:
The problem requires rotating a given 𝑛 × 𝑛 matrix by 90 degrees clockwise. The most efficient way to do this in-place (without using extra space for another matrix) is by performing two main operations:

1. Transpose the Matrix: Convert rows into columns and vice versa.
2. Reverse Each Row: After transposing, reverse each row to achieve the 90-degree rotation.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows (and columns since it's an n x n matrix)

        // Step 1: Transpose the matrix
        // Transposing means converting rows into columns and vice versa.
        for(int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        // Reversing each row gives the final rotated matrix.
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end()); // Reverse the ith row
        }
    }
};

/*
Explanation:

👉 Transpose the Matrix:
1. In the transpose of a matrix, the element at position (i, j) is swapped with the element at position (j, i).
2. This means that the element from the ith row and jth column moves to the jth row and ith column, effectively swapping rows and columns.
3. The loop runs until j < i to avoid swapping elements back and maintaining the original positions of diagonal elements.

👉 Reverse Each Row:
After transposing, each row is reversed to simulate a 90-degree rotation.
Reversing the rows ensures that elements move from their new transposed positions to their final rotated positions.

👉 Time Complexity:
The time complexity is O(n^2) because we are iterating through all elements of the matrix twice—once for the transpose and once for the reversal.

👉 Space Complexity:
The space complexity is O(1) because the rotation is done in place, meaning no extra space is used beyond a few temporary variables.
*/