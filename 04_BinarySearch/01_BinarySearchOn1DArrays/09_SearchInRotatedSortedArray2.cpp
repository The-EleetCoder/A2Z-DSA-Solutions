/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
*/

/*
You are given a rotated sorted array of integers, which means the array was initially sorted in ascending order but then rotated at some pivot point. The goal is to determine if a given target value exists in the array. Duplicates may also be present in the array. You need to implement a function that efficiently searches for the target using a modified binary search approach, considering the rotation and possible duplicates.
*/

class Solution {
public:
    // Function to search for a target in a rotated sorted array
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // If target is found at the middle, return true
            if (nums[mid] == target) return true;

            // If the values at start, mid, and end are the same, 
            // we cannot determine which part is sorted, so shrink the range
            if (nums[start] == nums[mid] && nums[end] == nums[mid]) {
                start++;
                end--;
                continue;
            }

            // If the left half of the array is sorted
            if (nums[mid] >= nums[start]) {
                // Check if the target is in the sorted left half
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;  // Narrow the search to the left half
                } else {
                    start = mid + 1;  // Narrow the search to the right half
                }
            }
            // Otherwise, the right half of the array is sorted
            else {
                // Check if the target is in the sorted right half
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;  // Narrow the search to the right half
                } else {
                    end = mid - 1;  // Narrow the search to the left half
                }
            }
        }
        // Return false if target is not found in the array
        return false;
    }
};


/*
The function searches for a target value in a rotated sorted array.
It uses a modified binary search approach to account for rotation.
The key observation is that in a rotated sorted array, at least one half of the array will always be sorted.
If the current start, mid, and end elements are equal, we cannot determine which half is sorted, so the search range is reduced by incrementing start and decrementing end.
The search checks which half (left or right) is sorted and based on where the target lies, it adjusts the search boundaries accordingly.
*/