/*
https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

/*
This problem involves searching for a target value in a matrix where:

1. Each row is sorted in ascending order from left to right.
2. Each column is sorted in ascending order from top to bottom.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();    // number of rows
        int m = matrix[0].size(); // number of columns

        int i = 0, j = m - 1, ans = -1;

        while (i < n and j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

/*
Intuition
We can treat the matrix as a grid with two dimensions: rows and columns. The key insight here is that because the matrix is sorted both row-wise and column-wise, we can take advantage of this structure to eliminate parts of the matrix efficiently, similar to how binary search works.

Steps:

👉 Start at the top-right corner: The element in the top-right corner (matrix[0][m-1]) is important because:
It is the largest element in its row (since the row is sorted).
It is the smallest element in its column (since the column is sorted).

👉 Compare the current element with the target:
If the current element is equal to the target, you've found the answer.
If the current element is larger than the target, move left (decrease the column index j) because all elements to the right are larger.
If the current element is smaller than the target, move down (increase the row index i) because all elements below are larger.

👉 Continue the process: Repeat this process of comparing and moving until you either find the target or move out of bounds.

Why this works:
By starting from the top-right corner, you can effectively eliminate either a row or a column after each comparison. This reduces the search space more efficiently than a brute-force approach, which would have taken O(n×m) time, where n is the number of rows and m is the number of columns.

This approach has a time complexity of O(n+m), as in each step, either the row or column is reduced by 1.
*/