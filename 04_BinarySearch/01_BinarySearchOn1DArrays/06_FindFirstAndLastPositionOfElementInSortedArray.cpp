/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

/*
The Solution class contains three methods: firstOccurrence, lastOccurrence, and searchRange. The firstOccurrence method finds the first occurrence of a target value in a sorted array. The lastOccurrence method finds the last occurrence of the target value. The searchRange method returns a vector containing the indices of the first and last occurrences of the target. If the target is not found, searchRange returns {-1, -1}.
*/

class Solution {
public:
    // Function to find the first occurrence of target in nums
    int firstOccurrence(vector<int>& nums, int target) {
        int first = -1; // Initialize the first occurrence to -1 (indicating not found)
        int start = 0; // Initialize the start index
        int end = nums.size() - 1; // Initialize the end index

        // Perform binary search within the range [start, end]
        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate the mid index to avoid overflow

            // If target is found, update first and continue searching in the left half
            if (nums[mid] == target) {
                first = mid;
                end = mid - 1; // Narrow the search to the left half to find the first occurrence
            }
            // If mid element is greater than target, search in the left half
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            // If mid element is less than target, search in the right half
            else {
                start = mid + 1;
            }
        }
        return first; // Return the index of the first occurrence or -1 if not found
    }

    // Function to find the last occurrence of target in nums
    int lastOccurrence(vector<int>& nums, int target) {
        int last = -1; // Initialize the last occurrence to -1 (indicating not found)
        int start = 0; // Initialize the start index
        int end = nums.size() - 1; // Initialize the end index

        // Perform binary search within the range [start, end]
        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate the mid index to avoid overflow

            // If target is found, update last and continue searching in the right half
            if (nums[mid] == target) {
                last = mid;
                start = mid + 1; // Narrow the search to the right half to find the last occurrence
            }
            // If mid element is greater than target, search in the left half
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            // If mid element is less than target, search in the right half
            else {
                start = mid + 1;
            }
        }
        return last; // Return the index of the last occurrence or -1 if not found
    }

    // Function to return the range [first, last] of the target in nums
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurrence(nums, target); // Get the first occurrence of target
        int last = lastOccurrence(nums, target); // Get the last occurrence of target
        return {first, last}; // Return the range as a vector
    }
};

/*
Key Points:

Binary Search: Both firstOccurrence and lastOccurrence use binary search to efficiently find the first and last occurrences of the target in O(log n) time complexity.

First and Last Occurrence Logic:
In firstOccurrence, if nums[mid] == target, it updates first to mid and continues searching in the left half to find the first occurrence.
In lastOccurrence, if nums[mid] == target, it updates last to mid and continues searching in the right half to find the last 
occurrence.

Edge Cases:
If the target is not found, both first and last remain -1, and searchRange returns {-1, -1}.
The methods correctly handle cases where the target is at the beginning, end, or spread across multiple locations in the array.
*/