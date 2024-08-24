/*
https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
*/


/*
To build an intuition for solving the problem of finding the longest subarray with a given sum k when the array contains only positive integers, let's break it down into logical steps:

👉 Problem Understanding:
Given a vector a of positive integers, you want to find the length of the longest contiguous subarray whose elements sum up to a given value k. The elements are positive, so if you add more elements to a subarray and the sum exceeds k, adding even more elements will only increase the sum further.

👉 Why Two Pointers / Sliding Window?
Since all elements are positive, once a subarray's sum exceeds k, you can be sure that extending this subarray further will not bring the sum back down to k. This key observation allows us to use a sliding window approach (two-pointer technique) efficiently:

1. Growing the Window:
Start with a window defined by two pointers, l (left) and r (right), both initially at the start of the array.
Expand the window by moving r to the right and adding a[r] to a running sum.

2. Shrinking the Window:
If sum exceeds k, you need to shrink the window from the left by moving l to the right and subtracting a[l] from the sum.
This shrinking ensures that the window only contains elements that might sum up to k as you continue moving r to the right.

3. Check for k:
Each time after adjusting the window (either by growing or shrinking), check if the current sum equals k.
If it does, calculate the length of the current window (r - l + 1) and update maxLen if this window is the longest one found so far.

👉 Intuition on the Sliding Window Technique:
The sliding window technique leverages the fact that with positive numbers, increasing the window size (moving r to the right) will only increase the sum or leave it unchanged (if the new element is zero). Conversely, decreasing the window size (moving l to the right) will decrease the sum or leave it unchanged.

This makes it possible to:
Efficiently find the longest subarray without checking all possible subarrays explicitly (which would take O(N^2) time).
Control the window size dynamically by expanding and contracting it based on the running sum.

👉 Why This Works for Positive Integers:
For positive integers, any time you overshoot the target sum k, you know you must reduce the window size to try to get back down to k. Once the sum is reduced to or below k, you can safely start expanding again.

👉 Visualizing the Process:
Imagine you're scanning the array with a window:
1. You expand the window until you overshoot k.
2. You then shrink the window from the left until you're back at or below k.
3. During this process, if at any point the sum equals k, you check if the current window is the largest one you've found.
*/


// Optimal approach - TC: O(N) - SC: O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {

    long long sum = a[0];
    int maxLen = 0;

    // Two pointers representing the left and right ends of the current subarray
    int l = 0;
    int r = 0;

    // Iterate until the right pointer reaches the end of the array
    while (r < a.size()) {

        while (l <= r && sum > k) {
            sum -= a[l];
            l++;
        }

        // Check if the current sum equals k
        if (sum == k) {
            maxLen = max(maxLen, r - l + 1);
        }

        r++;
        
        // Before adding the next element to the sum, check if r is still within bounds
        if (r < a.size()) {
            sum += a[r];
        }
    }
    return maxLen;
}


/*
👉 Initialization:
sum is initialized with the first element of the array. maxLen is used to track the maximum length of the subarray whose sum equals k.

👉 Two-Pointer Technique:
l and r are two pointers that represent the current subarray. l is the left pointer, and r is the right pointer.
The while loop continues as long as r is within the bounds of the array.
If the current sum exceeds k, the window is shrunk from the left (l pointer) until the sum is less than or equal to k.

👉 Condition Check:
If sum == k, the length of the current subarray (r - l + 1) is compared with maxLen, and maxLen is updated if the current subarray is longer.

👉 Edge Handling:
Before adding the next element to the sum, it's important to check if r is still within the array bounds to avoid out-of-bounds access.
*/