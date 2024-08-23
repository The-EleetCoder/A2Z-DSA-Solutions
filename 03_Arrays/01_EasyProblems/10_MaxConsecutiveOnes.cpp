/*
https://leetcode.com/problems/max-consecutive-ones/
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;   // To count consecutive 1s
        int result = 0;  // To store the maximum count of consecutive 1s

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;  // Increment the count if 1 is found
            } else {
                result = max(result, count); // Update result if current streak ends
                count = 0;  // Reset count when 0 is encountered
            }
        }

        result = max(result, count); // Update result in case the array ends with a streak of 1s
        return result;
    }
};
