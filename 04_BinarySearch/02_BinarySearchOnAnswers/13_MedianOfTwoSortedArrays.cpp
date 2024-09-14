/*
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

/*
Intuition:
This problem requires finding the median of two sorted arrays, which can be solved efficiently by using a binary search technique. The key challenge is merging two arrays without actually combining them and ensuring that the correct partition separates the elements correctly to compute the median.

Here’s the intuition behind the approach:

1. Binary Search on Smaller Array: Since the arrays are sorted, instead of merging them, we can leverage the properties of sorted arrays. We use binary search to partition the smaller array and compute the corresponding partition in the larger array to make sure both arrays are split into two halves, such that:

    1. The left half of the partition contains elements that are smaller or equal to the elements in the right half.
    2. This guarantees that when the two halves are combined, the middle values (for the median) can be easily identified.

2. Partitioning: By dividing the arrays into two halves, we ensure that:
    
    1. The total number of elements on the left of the partition is equal (or almost equal) to the number of elements on the right.
    2. For an odd number of total elements, the median is the maximum of the left partition.
    3. For an even number of total elements, the median is the average of the maximum value of the left partition and the minimum value of the right partition.

3. Handling Edge Cases: The algorithm handles edge cases where partitions involve the smallest or largest elements of either array. To do this, we set extreme values (INT_MIN, INT_MAX) when the partition crosses the array's boundary.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        // Ensure nums1 is the smaller array for simplicity
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2; // Calculate the left partition size
        int low = 0, high = n1;
        
        while (low <= high) {
            int mid1 = (low + high)/2; // Calculate mid index for nums1
            int mid2 = left - mid1; // Calculate mid index for nums2
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            // Determine values of l1, l2, r1, and r2
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            
            if (l1 <= r2 && l2 <= r1) {
                // The partition is correct, we found the median
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) {
                // Move towards the left side of nums1
                high = mid1 - 1;
            }
            else {
                // Move towards the right side of nums1
                low = mid1 + 1;
            }
        }
        
        return 0; // If the code reaches here, the input arrays were not sorted.
    }
};


/*
Approach:
Ensure nums1 is the smaller array: We ensure that we always apply binary search on the smaller array for efficiency. If nums1 is larger than nums2, we swap them. This simplifies the binary search as we are always partitioning the smaller array.

Binary Search on nums1:
The main idea is to partition both arrays such that the left half of the combined array contains the smaller elements and the right half contains the larger elements.
We perform binary search on nums1 to determine the partition point mid1, and then calculate the corresponding partition point mid2 for nums2.

Check Partition Validity:
For a valid partition, the following conditions must hold:
The largest element on the left side of nums1 (l1) must be less than or equal to the smallest element on the right side of nums2 (r2).
Similarly, the largest element on the left side of nums2 (l2) must be less than or equal to the smallest element on the right side of nums1 (r1).
If this condition is met, we've found the correct partition, and the median can be calculated based on whether the total number of elements is odd or even.

Adjust Binary Search:
If the partition is invalid, we adjust our search space:
If l1 > r2, it means the partition in nums1 is too far to the right, so we move mid1 to the left.
If l2 > r1, it means the partition in nums1 is too far to the left, so we move mid1 to the right.

Compute Median:
If the combined arrays have an odd length, the median is the maximum element from the left partition.
If the combined arrays have an even length, the median is the average of the maximum element from the left partition and the minimum element from the right partition.

Time Complexity:
Binary Search is performed on the smaller array (nums1), and at each step, we cut down the search space by half. Hence, the time complexity is O(log(min(n1, n2))).
Since we only calculate values at the partition points, the overall time complexity remains efficient.
*/