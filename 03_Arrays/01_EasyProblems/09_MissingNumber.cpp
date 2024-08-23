/*
https://leetcode.com/problems/missing-number/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_0_to_n = nums.size();  // Start with n
        int xor_nums = 0;

        for (int i = 0; i < nums.size(); i++) {
            xor_0_to_n = xor_0_to_n ^ i;   // XOR with the index
            xor_nums = xor_nums ^ nums[i]; // XOR with the array elements
        }

        int missingElement = xor_nums ^ xor_0_to_n;

        return missingElement;
    }
};

/*
Explanation:

XOR Operation:
XOR has a unique property: a ^ a = 0 and a ^ 0 = a.
By XOR-ing all numbers from 0 to n and XOR-ing all elements of the array, the duplicate numbers will cancel out, leaving only the missing number.

Initialization:
xor_0_to_n is initialized with n, and xor_nums is initialized with 0.
In the loop, xor_0_to_n is XOR-ed with indices and xor_nums with the array elements.

Final XOR:
After the loop, xor_0_to_n should have all numbers XOR-ed from 0 to n.
xor_nums will have all the numbers in the array XOR-ed.
The missing number is obtained by XOR-ing these two results.
*/