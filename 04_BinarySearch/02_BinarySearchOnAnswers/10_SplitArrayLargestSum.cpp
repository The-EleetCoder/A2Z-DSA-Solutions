/*
https://leetcode.com/problems/split-array-largest-sum/
*/

/*
The problem you're solving is based on partitioning an array into k non-empty subarrays such that the largest sum of any subarray is minimized. This is similar to the "Split Array Largest Sum" problem and can be solved using binary search with a greedy approach.

Intuition:
Objective:
We need to split the array nums into k subarrays such that the sum of elements in each subarray is minimized, and we want to find the minimal possible maximum sum across all subarrays.

Binary Search on the Maximum Subarray Sum:
We perform binary search on the possible values for the maximum sum of any subarray. The smallest possible value is the largest element in the array (start), because no subarray can have a sum smaller than this value. The largest possible value is the total sum of the array (end), which would occur if we placed all elements into one subarray.

Greedy Check (isPossible function):
For a given mid, which is the candidate value for the maximum sum of subarrays, we check whether it's possible to partition the array into at most k subarrays, where the sum of elements in each subarray is less than or equal to mid. If it's possible, we attempt to find a smaller maximum sum. Otherwise, we increase the value of mid.
*/

class Solution {
public:
    // This function checks if it's possible to split the array into at most `k` subarrays
    // such that the sum of elements in each subarray is less than or equal to `mid`.
    bool isPossible(vector<int>& nums, int k, int mid) {
        int current_sum = 0;     // Stores the sum of the current subarray
        int subarray_count = 1;  // Start with one subarray

        // Traverse through the array to form subarrays
        for (int i = 0; i < nums.size(); i++) {
            // If adding the current element exceeds the `mid` value, start a new subarray
            if (current_sum + nums[i] > mid) {
                current_sum = nums[i]; // Start a new subarray with the current element
                subarray_count++;      // Increment the number of subarrays

                // If the number of subarrays exceeds `k`, it's not possible with this `mid`
                if (subarray_count > k)
                    return false;
            } else {
                // Otherwise, keep adding elements to the current subarray
                current_sum += nums[i];
            }
        }

        // If we successfully split the array into at most `k` subarrays, return true
        return subarray_count <= k;
    }

    // Function to find the minimal possible maximum sum across `k` subarrays
    int splitArray(vector<int>& nums, int k) {
        // The minimum possible value for the maximum sum of subarrays is the largest element
        int start = *max_element(nums.begin(), nums.end());

        // The maximum possible value for the maximum sum of subarrays is the total sum of the array
        int end = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1; // This will store the result

        // Binary search to find the minimum possible maximum subarray sum
        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate mid as a candidate maximum subarray sum

            // Check if it's possible to split the array with this mid value
            bool possible = isPossible(nums, k, mid);

            if (possible) {
                // If it's possible, store the answer and try for a smaller maximum sum
                ans = mid;
                end = mid - 1;
            } else {
                // If it's not possible, increase the value of `mid`
                start = mid + 1;
            }
        }

        // Return the minimal possible maximum sum
        return ans;
    }
};

/*
isPossible Function:
This function checks if we can split the array into at most k subarrays such that the sum of elements in each subarray is less than or equal to mid.
The current_sum variable keeps track of the current subarray's sum. If adding the next element exceeds mid, we start a new subarray.
We keep counting the number of subarrays formed. If at any point the subarray count exceeds k, it means the current mid value is too small.

Binary Search:
We use binary search on the range of possible maximum subarray sums. The smallest possible sum (start) is the largest element in the array, while the largest possible sum (end) is the total sum of the array.
For each mid-point in the binary search, we check if it's possible to split the array with that mid value using the isPossible function. If it's possible, we try to reduce the maximum sum by moving the end pointer. If it's not possible, we increase the start pointer.

Optimal Answer:
The binary search narrows down the possible values for the maximum sum. The final result (ans) is the smallest value of mid that allows us to split the array into at most k subarrays.
*/