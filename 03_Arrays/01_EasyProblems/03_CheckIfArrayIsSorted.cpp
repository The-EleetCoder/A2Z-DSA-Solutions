/*
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        // Edge case: If the array has 2 or fewer elements, it's always "sorted".
        if (n <= 2) return true;

        int count = 0;

        // Count the number of "drops" or places where the array is not in ascending order.
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                count++;
            }
        }

        // Check the boundary between the last and the first element
        if (nums[n - 1] > nums[0]) count++;

        // If there's more than one "drop", it can't be a valid rotated sorted array.
        return count <= 1;
    }
};
