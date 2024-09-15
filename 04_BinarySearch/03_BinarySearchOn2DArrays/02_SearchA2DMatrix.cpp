/*
https://leetcode.com/problems/search-a-2d-matrix/
*/

/*
Using Binary Search 
first find the required row and then the required column.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(); // no. of rows
        int cols = matrix[0].size(); // no. of columns

        // finding ans row
        int row_start = 0;
        int row_end = rows - 1;
        int ans_row = -1;

        while (row_start <= row_end){
            int mid = row_start + (row_end - row_start)/2;

            if (target >= matrix[mid][0] && target <= matrix[mid][cols-1]){
                ans_row = mid;
                break;
            } else if (target < matrix[mid][0]){
                row_end = mid - 1;
            } else {
                row_start = mid + 1;
            }
        }
        if (ans_row == -1) return false;

        // finding ans col
        int col_start = 0;
        int col_end = cols - 1;

        while (col_start <= col_end){
            int mid = col_start + (col_end - col_start)/2;

            if (target == matrix[ans_row][mid]){
                return true;
            } else if (target < matrix[ans_row][mid]){
                col_end = mid - 1;
            } else {
                col_start = mid + 1;
            }
        }
        return false;
    }
};

