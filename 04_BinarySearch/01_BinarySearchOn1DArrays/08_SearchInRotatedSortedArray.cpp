/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

/*
The Solution class contains two methods: pivot and search. The pivot method identifies the index of the smallest element (pivot) in a rotated sorted array. The search method uses this pivot to perform a binary search, efficiently finding the target element's index in the rotated sorted array. If the target is not found, it returns -1.
*/

class Solution {
public:
    // Function to find the pivot (smallest element) in a rotated sorted array
    int pivot(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        // Perform binary search within the range [start, end]
        while (start < end) {
            int mid = start + (end - start) / 2;

            // If the mid element is greater than or equal to the first element,
            // the pivot must be in the right half
            if (nums[mid] >= nums[0]) {
                start = mid + 1;
            }
            // If the mid element is less than the first element,
            // the pivot could be the mid element or in the left half
            else {
                end = mid;
            }
        }
        return end;
    }

    // Function to search for the target in a rotated sorted array
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        // Find the pivot element in the rotated array
        int pivot_element = pivot(nums);

        // If the array is not rotated (i.e., its sorted), search in the entire array
        if (nums[0] <= nums[n - 1]) {
            start = 0;
        }
        // If the target is greater than or equal to the first element,
        // search in the left part (from start to pivot-1)
        else if (target >= nums[0]) {
            end = pivot_element - 1;
        }
        // Otherwise, search in the right part (from pivot to end)
        else {
            start = pivot_element;
        }

        // Perform binary search within the determined range [start, end]
        while (start <= end) {
            int mid = start + (end - start) / 2; 

            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return -1; // Return -1 if the target is not found
    }
};
