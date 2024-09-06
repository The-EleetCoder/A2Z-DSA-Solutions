/*
https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
*/

/*
Problem Intuition:

This problem requires finding the smallest divisor such that when dividing each element of the nums array by this divisor and summing up the ceiling of the divisions, the result is less than or equal to a given threshold.
We need to find the minimum divisor that allows the sum of the ceilings of the divisions to be within the threshold. This can be efficiently solved using binary search on the divisor values.

Key Insights:

Binary Search on Divisors:
The smallest divisor can be as low as 1 and as high as the maximum value in the nums array.
By performing a binary search on the divisor, we can efficiently find the minimum value that satisfies the condition.

Feasibility Check (Helper Function isPossible):
For a given divisor mid, we calculate the sum of the ceilings of each element divided by mid.
If this sum is less than or equal to threshold, then this divisor mid is valid, and we try to find a smaller one.

Binary Search Approach:
Start: Initialize the search with the smallest divisor start = 1.
End: Set the upper limit as the maximum element in nums, since dividing any number by a value larger than that won't reduce the sum.
Perform a binary search to find the smallest valid divisor.
*/

class Solution {
public:
    // Helper function to check if we can divide the numbers by 'mid' and keep the sum under 'threshold'
    int isPossible(vector<int>& nums, int threshold, int mid) {
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil((double)nums[i] / (double)mid);
        }
        return (sum <= threshold);
    }

    // Main function to find the smallest divisor
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        
        int ans = end;

        // Perform binary search
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Check if it's possible to divide by 'mid' and keep the sum under threshold
            int possible = isPossible(nums, threshold, mid);

            if (possible) {
                ans = mid;      // If it's possible, update the answer
                end = mid - 1;  // Try to find a smaller divisor in the left half
            } else {
                start = mid + 1;  // Otherwise, search the right half with larger divisors
            }
        }

        return ans;  // Return the smallest divisor found
    }
};

/*
Key Parts Explained:

Binary Search on Divisors:
We are searching for the smallest divisor mid between 1 and max(nums) that satisfies the condition. The binary search narrows down the range of possible divisors efficiently.

Helper Function (isPossible):
This function iterates over the nums array, divides each element by the divisor mid, and sums up the ceiling of the divisions.
If the sum of the divisions is less than or equal to threshold, the divisor mid is considered feasible, and we attempt to find a smaller one.

Binary Search Loop:
If the current divisor mid is feasible, we update the result (ans) and try a smaller divisor by shifting the search to the left (end = mid - 1).
If it's not feasible, we try larger divisors by shifting the search to the right (start = mid + 1).
*/