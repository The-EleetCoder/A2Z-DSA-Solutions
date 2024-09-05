/*
https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

/*
You are given a sorted array where every element appears twice except for one single non-duplicate element. The task is to find this single non-duplicate element using an efficient approach, ideally in O(log n) time using binary search.
*/

class Solution {
public:
    // Function to find the single non-duplicate element in a sorted array
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        // Perform binary search to find the single non-duplicate element
        while (start < end) {
            int mid = start + (end - start) / 2;

            // Check if mid is at an odd index
            if (mid % 2 != 0) {
                // If mid and the element to its left are the same, the single element is on the right
                if (nums[mid] == nums[mid - 1]) {
                    start = mid + 1;
                } 
                // Otherwise, the single element is on the left
                else {
                    end = mid;
                }
            } 
            // If mid is at an even index
            else {
                // If mid and the element to its right are the same, the single element is on the right
                if (nums[mid] == nums[mid + 1]) {
                    start = mid + 1;
                } 
                // Otherwise, the single element is on the left
                else {
                    end = mid;
                }
            }
        }
        return nums[end];
    }
};

/*
The function finds the single non-duplicate element in a sorted array where every other element appears twice.
It uses a binary search approach to efficiently locate the single element.
The key observation is that for a pair of duplicate elements, their first occurrence appears at an even index and the second at an odd index.
By comparing the middle element with its neighbors, the search narrows down to the half where the single element is located.
The process continues until the single element is found.
*/