/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

/*
You are given a rotated sorted array of unique integers, and the task is to find and return the minimum element. The goal is to implement an efficient solution with a time complexity better than linear search.
*/

class Solution {
public:
    // Function to find the minimum element in a rotated sorted array
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        // Perform a binary search to find the minimum element
        while (start < end) {
            int mid = start + (end - start) / 2;

            // If the array is sorted from start to end, return the element at start
            if (nums[mid] >= nums[start] && nums[mid] <= nums[end]) {
                return nums[start];
            }
            // If the left half is sorted, search in the right half
            else if (nums[mid] >= nums[start]) {
                start = mid + 1;
            }
            // If the right half is unsorted, search in the left half
            else {
                end = mid;
            }
        }
        // Return the minimum element after binary search
        return nums[end];
    }
};

/*
The function finds the minimum element in a rotated sorted array.
It uses binary search to efficiently find the minimum by leveraging the fact that in a rotated sorted array, one half of the array will always be sorted.
If the array between start and end is already sorted, the smallest element is at the start index.
Otherwise, the function narrows down the search range by adjusting either start or end, depending on which part of the array is sorted.
The loop continues until the smallest element is found and returned.
*/