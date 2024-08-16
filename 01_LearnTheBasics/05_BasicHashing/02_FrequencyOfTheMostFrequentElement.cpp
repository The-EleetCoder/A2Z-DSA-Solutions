/*
https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/
*/

// Using sliding window method
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Sort the array to make it easier to calculate frequency of equal elements
        sort(nums.begin(), nums.end());

        int left, right = 0;       // Left and Right pointer of the window
        long long totalSum = 0;    // Sum of elements in the current window
        int ans = 0;               // Variable to store the maximum frequency

        // Traverse the array with the right pointer
        while (right < nums.size()) {
            totalSum += nums[right]; // Add the current element to the total sum

            // Check if the current window can be made into the same element with at most 'k' operations
            while (nums[right] > (totalSum + k)/(right - left + 1)) {
                // If not, shrink the window from the left
                totalSum -= nums[left];
                left++;
            }

            // Update the answer with the maximum size of the valid window
            ans = max(ans, right - left + 1);
            right++;  // Expand the window by moving the right pointer
        }

        return ans;  // Return the maximum frequency
    }
};

