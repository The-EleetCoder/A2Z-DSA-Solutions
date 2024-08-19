/*
https://leetcode.com/problems/rotate-array/
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Reduce k to be within the bounds of the array size
        k = k % nums.size();
        
        // If k is 0 after the modulus operation, no rotation is needed
        if (k == 0) {
            return;
        }

        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining elements from k to the end of the array
        reverse(nums.begin() + k, nums.end());
    }
};