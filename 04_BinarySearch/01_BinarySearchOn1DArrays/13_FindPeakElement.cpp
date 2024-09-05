/*
https://leetcode.com/problems/find-peak-element/
*/

/*
The goal is to find a "peak" element in the array, where a peak element is one that is greater than its neighbors. The key idea behind the solution is to use a binary search to efficiently find a peak. We can do this because if an element is smaller than its next neighbor, then a peak must exist on the right half of the array. Conversely, if an element is greater than or equal to its next neighbor, a peak must exist on the left side. This property allows us to eliminate half of the search space at each step, similar to binary search.
*/

class Solution {
public:
    // Function to find the index of a peak element in the array
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        // Perform binary search to find a peak element
        while (start < end) {
            int mid = start + (end - start) / 2;  

            // Check if mid is a peak element (greater than both neighbors)
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            } 
            // If the right neighbor is greater, then a peak must exist on the right half
            else if (nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            } 
            // Otherwise, a peak must exist on the left half
            else {
                end = mid;
            }
        }
        // When start == end, we have found the peak, return the index
        return start;
    }
};


/*
The task is to find a peak element in an array. A peak element is defined as an element that is greater than its neighbors. The problem guarantees that at least one peak element exists, so the array is not empty.

Approach:
We use a binary search to efficiently find a peak element in the array. The intuition behind this approach is based on the following 

observations:

Binary Search and Midpoint:
We divide the array by choosing a midpoint (i.e., mid = (start + end) / 2).
We then compare the middle element (nums[mid]) with its neighbors (nums[mid-1] and nums[mid+1]).

Peak Identification:
If the middle element is greater than both its left (nums[mid - 1]) and right (nums[mid + 1]) neighbors, then nums[mid] is a peak element, and we return mid.

Move Towards Peak:
If the middle element is less than its right neighbor (nums[mid] < nums[mid + 1]), it indicates that a peak must exist to the right of mid. This is because, if the next element is greater, the slope is increasing, and there must be a peak on that side.
Conversely, if the middle element is greater than or equal to its right neighbor (nums[mid] >= nums[mid + 1]), it suggests that a peak must exist to the left of mid, either at mid or earlier. This is because, if the next element is smaller, the slope is decreasing, and there could be a peak either at mid or on the left side.

Narrowing the Search:
By always narrowing the search space based on the direction where a peak is more likely to exist, we reduce the problem size by half in each step. This ensures a logarithmic time complexity.

Convergence:
Eventually, the start and end pointers converge to the same element, which is guaranteed to be a peak because of the way we moved the pointers.

Why Binary Search Works:
In a normal array, an element either leads to an increase or decrease in the value of its neighbors. If the middle element is not a peak, moving towards the side where a larger element exists will lead us to a peak.
Local peaks always exist because either an element is greater than its neighbors, or the array ends (i.e., boundary conditions ensure a peak if the array is increasing or decreasing).

Time Complexity:
The time complexity of this algorithm is O(log n) because we reduce the search space by half at each step, similar to a traditional binary search.
*/
