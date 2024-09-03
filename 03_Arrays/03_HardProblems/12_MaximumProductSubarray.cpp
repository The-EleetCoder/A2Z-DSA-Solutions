/*
https://leetcode.com/problems/maximum-product-subarray/
*/

/*
The code implements a solution to find the maximum product of a contiguous subarray within a given array of integers. The approach leverages the idea of maintaining both a prefix product (from the start) and a suffix product (from the end) to handle cases where the maximum product might involve negative numbers or zeros. The overall time complexity is O(n).
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefixProduct = 1;   // To track the product of elements from the start
        int suffixProduct = 1;   // To track the product of elements from the end
        int maxProduct = INT_MIN; // Initialize maxProduct to the smallest possible integer

        // Iterate through the array to compute the maximum product
        for (int i = 0; i < n; i++) {
            // If the prefix product becomes zero, reset it to 1
            if (prefixProduct == 0) prefixProduct = 1;
            // If the suffix product becomes zero, reset it to 1
            if (suffixProduct == 0) suffixProduct = 1;

            // Update the suffix product by multiplying the current element from the end
            suffixProduct *= nums[n - i - 1];
            // Update the prefix product by multiplying the current element from the start
            prefixProduct *= nums[i];

            // Update maxProduct with the maximum of the current maxProduct, prefixProduct, and suffixProduct
            maxProduct = max(maxProduct, max(suffixProduct, prefixProduct));
        }

        return maxProduct; // Return the maximum product found
    }
};
