/*
https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
*/

// Unlike the previous question, the input array include only positives, so the solution could be optimized more using 2 pointer approach (sliding window)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Initialize the sum with the first element of the array
    long long sum = a[0];
    // Variable to track the maximum length of the subarray with sum k
    int maxLen = 0;

    // Two pointers representing the left and right ends of the current subarray
    int l = 0;
    int r = 0;

    // Iterate until the right pointer reaches the end of the array
    while (r < a.size()) {
        // Shrink the window from the left if the current sum exceeds k
        while (l <= r && sum > k) {
            sum -= a[l];  // Subtract the leftmost element from the sum
            l++;          // Move the left pointer to the right
        }

        // Check if the current sum equals k
        if (sum == k) {
            // Update maxLen if the current subarray is longer than the previously found ones
            maxLen = max(maxLen, r - l + 1);
        }

        // Move the right pointer to the right to explore the next element
        r++;

        // Before adding the next element to the sum, check if r is still within bounds
        if (r < a.size()) {
            sum += a[r];  // Add the next element to the sum
        }
    }

    // Return the maximum length of the subarray with sum k
    return maxLen;
}

/*
Explanation:

Initialization:
sum is initialized with the first element of the array. maxLen is used to track the maximum length of the subarray whose sum equals k.

Two-Pointer Technique:
l and r are two pointers that represent the current subarray. l is the left pointer, and r is the right pointer.
The while loop continues as long as r is within the bounds of the array.
If the current sum exceeds k, the window is shrunk from the left (l pointer) until the sum is less than or equal to k.

Condition Check:
If sum == k, the length of the current subarray (r - l + 1) is compared with maxLen, and maxLen is updated if the current subarray is longer.

Edge Handling:
Before adding the next element to the sum, it's important to check if r is still within the array bounds to avoid out-of-bounds access.
*/