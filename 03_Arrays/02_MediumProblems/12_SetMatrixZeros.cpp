/*
https://leetcode.com/problems/set-matrix-zeroes/
*/

// Brute Force - WORKS ONLY WITH POSITIVE NUMBERS
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Get the number of rows in the matrix
        int m = matrix[0].size(); // Get the number of columns in the matrix

        // First pass: Identify the rows and columns that should be set to zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) { // If a zero is found in the matrix
                    int i1 = 0;
                    int j1 = 0;

                    // Mark the entire column (excluding zero elements) by setting non-zero elements to -1
                    while (i1 < n) {
                        if (matrix[i1][j] != 0) 
                            matrix[i1][j] = -1;
                        i1++;
                    }

                    // Mark the entire row (excluding zero elements) by setting non-zero elements to -1
                    while (j1 < m) {
                        if (matrix[i][j1] != 0)
                            matrix[i][j1] = -1;
                        j1++;
                    }
                }
            }
        }

        // Second pass: Replace all marked elements (-1) and original zeros with 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0 || matrix[i][j] == -1) {
                    matrix[i][j] = 0; // Set elements to zero
                }
            }
        }
    }
};


/*
Better Approach

Intuition:
The goal of this algorithm is to set the entire row and column to zero if any element in that row or column is zero. To achieve this, we use two additional arrays, row and column, to keep track of which rows and columns should be set to zero. The algorithm proceeds in two main steps:

First Pass: Traverse the matrix to identify which rows and columns need to be zeroed out and mark them in the row and column arrays.
Second Pass: Use the information in the row and column arrays to update the matrix, setting the appropriate rows and columns to zero.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows
        int m = matrix[0].size(); // Number of columns

        // Arrays to mark which rows and columns need to be set to zero
        vector<int> row(n, 0);    // Initially, no rows are marked
        vector<int> column(m, 0); // Initially, no columns are marked

        // First pass: Identify rows and columns that need to be zeroed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = -1;      // Mark the row for zeroing
                    column[j] = -1;   // Mark the column for zeroing
                }
            }
        }

        // Second pass: Set the appropriate rows and columns to zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == -1 || column[j] == -1) {
                    matrix[i][j] = 0; // Set matrix element to zero
                }
            }
        }
    }
};


/*
Optimal approach

Intuition:
The goal is to set the entire row and column to zero if any element in that row or column is zero.
Instead of using additional space (like arrays), we can use the first row and the first column of the matrix itself to store markers. This reduces the space complexity to O(1).
We also need a separate flag col0 to track whether the first column itself should be zeroed.

Step-by-Step Explanation:

1. Initialization:
We start by initializing col0 to 1. This flag helps track whether the first column needs to be zeroed at the end.

2. First Pass - Marking Phase:
We traverse the matrix to identify zeros.
If a zero is found at position (i, j), we mark the first element of that row (matrix[i][0]) and the first element of that column (matrix[0][j]).
If the zero is in the first column (j == 0), we set col0 to 0.

3. Second Pass - Zeroing Phase (excluding the first row and column):
We traverse the matrix again, starting from (1,1) to the end.
For each element (i, j), if either matrix[0][j] or matrix[i][0] is zero, we set matrix[i][j] to zero.

4. Handle the First Row:
We handle the first row separately by traversing from the last column to the second column (m-1 to 1).
If the first element of the first row (matrix[0][0]) is zero, we set all elements in the first row to zero.

5. Handle the First Column:
Finally, we handle the first column by checking the col0 flag.
If col0 is zero, we set all elements in the first column to zero.

Time Complexity:
The time complexity is O(n×m), where n is the number of rows and m is the number of columns, because we traverse the entire matrix twice.
Space Complexity:
The space complexity is O(1) since we are using the matrix itself to store markers and only one additional variable (col0) is used.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows
        int m = matrix[0].size(); // Number of columns

        int col0 = 1; // Flag to indicate if the first column should be set to zero

        // First pass: Mark the first row and column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // Mark the current row
                    matrix[i][0] = 0;

                    // Mark the current column
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0; // If the zero is in the first column, mark col0
                }
            }
        }

        // Second pass: Use marks to set elements to zero, except the first row and column
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0; // Set element to zero if its row or column is marked
                }
            }
        }

        // Handle the first row separately
        for (int i = m - 1; i > 0; i--) {
            if (matrix[0][0] == 0) {
                matrix[0][i] = 0; // Set the first row to zero if it was marked
            }
        }

        // Handle the first column separately
        for (int i = 0; i < n; i++) {
            if (col0 == 0) {
                matrix[i][0] = 0; // Set the first column to zero if col0 was marked
            }
        }
    }
};
