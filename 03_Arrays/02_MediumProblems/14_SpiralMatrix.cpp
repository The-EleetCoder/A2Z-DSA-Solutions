/*
https://leetcode.com/problems/spiral-matrix/
*/

/*
The task is to traverse a matrix in a spiral order, starting from the top-left corner and moving towards the center, collecting elements as we go. This involves iteratively moving right across the top row, down the rightmost column, left across the bottom row, and up the leftmost column, and then repeating the process for the next inner layer.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();       // Number of rows
        int col = matrix[0].size();    // Number of columns

        vector<int> ans;  // Vector to store the elements in spiral order

        int top = 0;     // Top boundary
        int bottom = row - 1; // Bottom boundary
        int left = 0;    // Left boundary
        int right = col - 1;  // Right boundary

        while (top <= bottom && left <= right) {
            // Traverse from left to right across the top row
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down

            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary left

            // Traverse from right to left across the bottom row (if still within boundaries)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up
            }

            // Traverse from bottom to top along the left column (if still within boundaries)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary right
            }
        }

        return ans;  // Return the spiral order
    }
};


/*
Explanation:

Boundary Variables:
top, bottom, left, and right represent the current boundaries of the matrix that need to be traversed.

Traversing the Matrix:
The loop runs as long as there are rows and columns left to traverse (top <= bottom and left <= right).
The four for loops inside the while loop handle the four directions: moving right, down, left, and up.

Boundary Updates:
After each direction traversal, the corresponding boundary is adjusted (top++, bottom--, left++, right--) to move inward to the next layer.

Edge Cases:
The checks if (top <= bottom) and if (left <= right) ensure that we don't traverse rows or columns that have already been fully processed, preventing duplication of elements or accessing invalid indices.

Time Complexity:
The time complexity is O(n×m), where n is the number of rows and m is the number of columns, as we visit each element exactly once.
Space Complexity:
The space complexity is O(1) (excluding the output vector ans), as we do not use any additional data structures other than variables for the boundaries.
*/