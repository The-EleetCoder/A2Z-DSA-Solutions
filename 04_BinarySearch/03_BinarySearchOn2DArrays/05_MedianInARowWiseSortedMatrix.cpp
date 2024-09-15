/*
https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
*/

/*
The problem is about finding the median of a row-wise sorted matrix with R rows and C columns. In a matrix, the median is defined as the element that would appear in the middle if all the elements were sorted.

Key Insight:
1. Matrix is row-wise sorted: This means that each row is sorted in increasing order. However, the matrix as a whole may not be fully sorted.
2. Median in a 1D array: If you had a 1D array of all the elements in the matrix, the median would be the (R×C+1)/2-th smallest element.
3. Binary search on element values: Instead of flattening the matrix into a 1D array (which would take O(R×C) space), we can leverage binary search on the possible element values in the matrix to find the median efficiently.
*/

int median(vector<vector<int>> &matrix, int R, int C) {
    int mi = INT_MAX;
    int mx = INT_MIN;
    
    // Step 1: Find the minimum and maximum element in the matrix
    for (int i = 0; i < R; i++) {
        mi = min(mi, matrix[i][0]);         // First element of each row
        mx = max(mx, matrix[i][C - 1]);     // Last element of each row
    }

    int ans;
    // Step 2: Binary search on the range [mi, mx]
    while (mi <= mx) {
        int mid = mi + (mx - mi) / 2;  // Avoid overflow in mid calculation
        
        // Step 3: Count how many elements are <= mid
        int cnt = 0;
        for (int i = 0; i < R; i++) {
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        // Step 4: Adjust the binary search range based on the count
        if (cnt >= (R * C + 1) / 2) {
            ans = mid;
            mx = mid - 1;  // Look for a smaller potential median
        } else {
            mi = mid + 1;  // Look for a larger potential median
        }
    }

    // Step 5: Return the median
    return ans;
}

/*
Approach Explanation:

Find the minimum (mi) and maximum (mx) element in the matrix:
The minimum is the smallest element in the first column, and the maximum is the largest element in the last column (because each row is sorted).
These values define the range [mi,mx] within which the median must lie.

Binary search on the value range [mi,mx]:
In each step of the binary search, we pick a middle value mid and count how many elements in the matrix are less than or equal to mid.
If this count is greater than or equal to the median position (i.e., (R×C+1)/2), it means mid could be the median, so we adjust our range to the left to find a smaller candidate.
If the count is less, it means the median is larger than mid, so we adjust the range to the right.

Count elements less than or equal to mid:
For each row in the matrix, we use upper_bound to count how many elements are less than or equal to mid. upper_bound returns an iterator to the first element greater than mid, so the count of elements less than or equal to mid in that row is given by upper_bound - begin.

Return the median:
When the binary search completes, ans holds the median value.


Key Steps:

Find the minimum and maximum values:
Iterate through the matrix to find the smallest element in the first column (mi) and the largest element in the last column (mx).

Binary search on value range:
The search is performed between mi and mx.
For each mid-value, count how many elements in the matrix are less than or equal to mid.

Adjust range based on count:
If the count of elements less than or equal to mid is at least half of the total elements, we update ans and search to the left for a potentially smaller median.
Otherwise, we search to the right.
*/