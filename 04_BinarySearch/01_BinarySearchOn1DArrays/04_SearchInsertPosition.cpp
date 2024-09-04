/*
https://leetcode.com/problems/search-insert-position/
*/

/*
The searchInsert function finds the index at which a target value should be inserted into a sorted array nums to maintain its order. If the target is already present in the array, the function returns the index of the target. Otherwise, it returns the index where the target can be inserted.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Initialize answer to the size of the array (default insertion point)
        int ans = nums.size(); 

        int start = 0; // Initialize the start index
        int end = nums.size() - 1; // Initialize the end index

        // Perform binary search within the range [start, end]
        while (start <= end) {
            // Calculate the mid index to avoid overflow
            int mid = start + (end - start) / 2; 

            // If the target is found at the mid index, return its index
            if (nums[mid] == target) {
                ans = mid;
                break;
            }
            // If the mid value is less than the target, search in the right half
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            // If the mid value is greater than the target, update ans to mid and search in the left half
            else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans; // Return the index where the target should be inserted
    }
};

/*
Key Points:

Binary Search: This function uses binary search to find the appropriate insertion index in O(log n) time complexity.

Insert Logic:
If the target is found in the array, ans is set to the target's index, and the loop exits.
If the target is not found and is greater than nums[mid], the search continues in the right half.
If the target is less than nums[mid], ans is updated to mid, and the search continues in the left half.

Insertion Point: The variable ans is initialized to nums.size() to handle the case where the target is greater than all elements in the array, making it the insertion point at the end. If the target is smaller than an element, ans is updated accordingly during the search.
*/
