/*
https://leetcode.com/problems/maximum-subarray/
*/

/*
This solution is an implementation of Kadane's Algorithm, which is used to find the maximum sum of a contiguous subarray within a one-dimensional array of numbers. Let's break down the intuition and add comments to the code.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        Initialize max_sum with the first element of the array.
        This is the best result we have so far
        */
        int max_sum = nums[0];

        /*
        Initialize current_sum with the first element of the array.
        This keeps track of the sum of the current subarray
        */
        int current_sum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            /*
            If current_sum is negative and the current element is greater than current_sum, 
            it's better to start a new subarray with nums[i]
            */
            if(current_sum < 0 && current_sum < nums[i]) {
                current_sum = nums[i];
            } 
            // Otherwise, add the current element to the current subarray
            else {
                current_sum += nums[i];
            }
            
            // Update max_sum if the current subarray sum is the largest we've seen so far
            if (current_sum >= max_sum) {
                max_sum = current_sum;
            } 
            else {
                continue;
            }
        }
        return max_sum;
    }
};


/*
The simplified version uses the max function to determine whether to start a new subarray or continue the existing one.
It eliminates unnecessary conditions and focuses on maintaining the maximum subarray sum seen so far.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            /*
            If adding the current element to current_sum is worse than starting fresh,
            start fresh with the current element
            */
            current_sum = max(nums[i], current_sum + nums[i]);
            // Update max_sum to be the largest sum we've seen
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};