/*
https://leetcode.com/problems/binary-search/
*/

/*
The search method implements a binary search algorithm to find the index of a given target value in a sorted array nums. If the target is found, it returns the index; otherwise, it returns -1.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Initialize the start index
        int start = 0; 
        
        // Initialize the end index
        int end = nums.size() - 1; 

        // Perform binary search within the range [start, end]
        while (start <= end) {
            // Calculate the mid index to avoid overflow
            int mid = start + (end - start) / 2; 

            // If the target is found at the mid index, return the index
            if (nums[mid] == target) return mid;
            
            // If the target is smaller than the mid value, narrow the search to the left half
            else if (nums[mid] > target) end = mid - 1;
            
            // If the target is larger than the mid value, narrow the search to the right half
            else start = mid + 1;
        }

        // If the target is not found, return -1
        return -1;
    }
};


// Using Recursion
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1); // Start the recursion
    }
    
private:
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        // Base case: If the range is invalid, the target is not in the array
        if (start > end) return -1;

        int mid = start + (end - start) / 2; // Calculate the mid index to avoid overflow

        // If the target is found at the mid index, return the index
        if (nums[mid] == target) return mid;
        // If the target is smaller than the mid value, search in the left half
        else if (nums[mid] > target) return binarySearch(nums, target, start, mid - 1);
        // If the target is larger than the mid value, search in the right half
        else return binarySearch(nums, target, mid + 1, end);
    }
};

