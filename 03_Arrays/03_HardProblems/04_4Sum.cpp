/*
https://leetcode.com/problems/4sum/
*/

/*
This implementation of the fourSum function extends the logic of the threeSum problem to find all unique quadruplets in the array nums that sum up to a given target. The approach uses sorting and the two-pointer technique to efficiently find the quadruplets.

Intuition and Explanation:

Sorting: The first step is to sort the array nums. This allows for the efficient use of the two-pointer technique, similar to the threeSum problem.

Two Nested Loops:
The outer loop (i) selects the first element of the quadruplet.
The inner loop (j) selects the second element of the quadruplet.

Skip Duplicates: Both loops skip over duplicate values to ensure that only unique quadruplets are considered.

Two-Pointer Technique:
After selecting the first two elements (nums[i] and nums[j]), two pointers (k and l) are used to find the other two elements that, when added to nums[i] and nums[j], sum to the target.
Adjusting Pointers: If the sum of the four elements is greater than the target, the right pointer (l) is moved left to reduce the sum. If the sum is less than the target, the left pointer (k) is moved right to increase the sum.
Finding a Quadruplet: When the sum is exactly equal to the target, a valid quadruplet is found and added to the result.

Handling Duplicates:
After finding a valid quadruplet, both pointers (k and l) are moved to the next different elements to avoid adding duplicate quadruplets to the result.

Time Complexity: The time complexity of this approach is O(n^3), where n is the number of elements in the array. This is the best possible complexity for the problem since all quadruplets need to be checked.
Space Complexity: The space complexity is O(1) beyond the space used to store the output, as the sorting is done in-place.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Result vector to store the quadruplets
        vector<vector<int>> ans;  
        // Sort the array to enable the two-pointer approach
        sort(nums.begin(), nums.end());  
        int n = nums.size();

        // First loop to pick the first element:
        for (int i = 0; i < n; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;  

            // Second loop to pick the second element:
            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  

                int k = j + 1;  // Left pointer
                int l = n - 1;  // Right pointer

                // Two-pointer approach to find the remaining two elements:
                while (k < l) {
                    // Calculate the current sum:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum > target) {
                        // If the sum is greater than target, move the right pointer to reduce the sum
                        l--;
                    } else if (sum < target) {
                        // If the sum is less than target, move the left pointer to increase the sum
                        k++;
                    } else {
                        // If the sum is exactly equal to target, we found a valid quadruplet
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);

                        // Move both pointers to the next different elements to avoid duplicates
                        k++;
                        l--;

                        // Skip duplicates for the left pointer
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        // Skip duplicates for the right pointer
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                }
            }
        }

        // Return the list of all unique quadruplets
        return ans;  
    }
};
