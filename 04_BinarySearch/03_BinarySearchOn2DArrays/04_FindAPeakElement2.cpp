/*
https://leetcode.com/problems/find-a-peak-element-ii/
*/

/*
This problem is about finding a peak in a 2D grid, where a peak is defined as an element that is greater than or equal to its four neighbors (up, down, left, and right). The goal is to find the index of one peak in the grid.
*/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int start = 0;
        int end = row - 1;

        while (start <= end){
            int mid = start + (end - start)/2;

            auto max_it = max_element(mat[mid].begin(), mat[mid].end());
            int max_index = distance(mat[mid].begin(), max_it);
            int max_ele = mat[mid][max_index];

            if ((mid==0 || mat[mid-1][max_index] < max_ele) && 
            (mid == row-1 || mat[mid+1][max_index] < max_ele)){
                return {mid, max_index};
            } else if ( mid-1 >= 0 && (mat[mid-1][max_index] > max_ele)){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return {-1,-1};
    }
};

/*
Approach Explanation

The approach used in this code is binary search applied to the rows of the matrix. Here’s the breakdown:

Key Observations:
You don't need to find the global maximum across the entire matrix. It suffices to find a local peak, which can be identified by comparing a number with its neighbors.
By applying binary search on the rows, the problem can be reduced efficiently, leading to a logarithmic reduction in the number of rows considered.

Step-by-Step Walkthrough:

Initialize binary search on rows:
Set start to 0 (beginning of the rows) and end to row - 1 (last row). You will perform binary search on the row index.

Iterate using binary search:
Find the middle row (mid): This is calculated as start + (end - start) / 2 to avoid overflow.
Find the maximum element in the middle row: Using max_element, find the column index (max_index) where the maximum element of the middle row lies. This is done because we are only interested in the potential peak elements in this row.

Peak condition check:
The current element is considered a peak if:
It is greater than or equal to the element in the row above (if it exists).
It is greater than or equal to the element in the row below (if it exists).
If these conditions are satisfied, the element at (mid, max_index) is a peak, and the algorithm returns this index.

Update the binary search boundaries:
If the element above the maximum in the middle row is greater, it means there is a higher peak in the upper half of the matrix. Thus, you move the search to the upper half by setting end = mid - 1.
If the element below the maximum in the middle row is greater, the peak is likely in the lower half. You move the search to the lower half by setting start = mid + 1.

Termination:
The algorithm will eventually find a peak and return its coordinates. If no peak is found, which theoretically shouldn't happen, it returns {-1, -1}.

Time Complexity:
Row-wise binary search: Reduces the number of rows to search in logarithmic time O(logn), where n is the number of rows.
Finding the maximum in a row: Takes O(m), where m is the number of columns.
Thus, the overall time complexity is O(m⋅logn).
This approach efficiently narrows down the search space by using binary search on the rows, making it much faster than a brute-force O(n⋅m) approach.
*/