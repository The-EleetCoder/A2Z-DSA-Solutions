/*
https://leetcode.com/problems/rearrange-array-elements-by-sign/
*/

/*
Intuition:
The problem involves rearranging an array such that positive and negative numbers alternate while maintaining their relative order from the original array. The idea is to use two pointers, one for positive numbers and one for negative numbers, and populate a new array accordingly.
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> arr; // Resultant array to store rearranged elements
        int p = 0; // Pointer to find the next positive number in nums
        int n = 0; // Pointer to find the next negative number in nums

        // Iterate over the nums array to fill the new array with alternating signs
        for (int i = 0; i < nums.size(); i++) {
            // Move the positive pointer to the next positive number
            while (p < nums.size() && nums[p] < 0) {
                p++;
            }

            // Move the negative pointer to the next negative number
            while (n < nums.size() && nums[n] > 0) {
                n++;
            }

            // If the current index is even, place the next positive number
            if (i % 2 == 0) {
                arr.push_back(nums[p++]);
            }
            // If the current index is odd, place the next negative number
            else {
                arr.push_back(nums[n++]);
            }
        }
        return arr;
    }
};
