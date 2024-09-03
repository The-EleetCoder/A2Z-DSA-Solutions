/*
https://leetcode.com/problems/reverse-pairs/
*/

/*
This code implements a solution to count the number of reverse pairs in an array, where a reverse pair is defined as two indices i and j such that i < j and nums[i] > 2 * nums[j]. The solution uses a modified merge sort algorithm to efficiently count reverse pairs while sorting the array. The overall time complexity of the algorithm is O(n log n), which is optimal for this type of problem.
*/

class Solution {
public:
    // Function to merge two sorted subarrays and count the number of reverse pairs
    long long int merge(vector<int>& nums, int l, int m, int r) {
        vector<int> temp(r - l + 1); // Temporary vector for merging subarrays
        int k = 0; // Index for temp vector
        int i = l; // Start index for the left subarray
        int j = m + 1; // Start index for the right subarray
        long long int count = 0; // Count of reverse pairs

        // Count reverse pairs
        while (i <= m) {
            // For each element in the left subarray, find the number of valid reverse pairs
            while (j <= r && nums[i] > 2 * (long long)nums[j]) {
                j++; // Move j forward to find the range of elements in the right subarray that satisfy the condition
            }
            // Add the number of valid reverse pairs for the current i
            count += (j - (m + 1));
            i++;
        }

        // Reset i and j to merge the subarrays
        i = l;
        j = m + 1;

        // Merge the two subarrays while maintaining the sorted order
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++]; // Take element from left subarray
            } else {
                temp[k++] = nums[j++]; // Take element from right subarray
            }
        }

        // Copy any remaining elements from the left subarray
        while (i <= m) {
            temp[k++] = nums[i++];
        }

        // Copy any remaining elements from the right subarray
        while (j <= r) {
            temp[k++] = nums[j++];
        }

        // Copy the merged elements back into the original array
        for (int i = 0; i < temp.size(); i++) {
            nums[l + i] = temp[i];
        }

        return count;
    }

    // Recursive function to perform merge sort and count reverse pairs
    long long int mergeSort(vector<int>& nums, int l, int r) {
        long long int count = 0;
        if (l < r) {
            int mid = l + (r - l) / 2; // Find the middle point

            // Recursively sort and count reverse pairs in the left half
            count += mergeSort(nums, l, mid);

            // Recursively sort and count reverse pairs in the right half
            count += mergeSort(nums, mid + 1, r);

            // Merge the two halves and count cross reverse pairs
            count += merge(nums, l, mid, r);
        }
        return count;
    }

    // Main function to count reverse pairs in the array
    long long int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1); // Start merge sort from the whole array
    }
};
