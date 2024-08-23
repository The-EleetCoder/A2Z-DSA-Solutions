/*
https://leetcode.com/problems/single-number/
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNumber = 0; // Initialize to 0 since x ^ 0 = x

        for (int i = 0; i < nums.size(); i++) {
            singleNumber = singleNumber ^ nums[i]; // XOR all the elements
        }

        return singleNumber; // The result is the single number
    }
};
