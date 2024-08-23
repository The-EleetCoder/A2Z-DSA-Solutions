/*
https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
*/

// Optimal Approach - Using Map (The array includes both -ves and +ves) - TC: O(N) - SC: O(N)
class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int k) 
    { 
        // Map to store the cumulative sum and its first occurrence index
        map<int, int> mpp;

        // Variables to store the cumulative sum and the maximum length of the subarray
        int sum = 0;
        int maxLen = 0;

        // Iterate over the array
        for (int i = 0; i < N; i++) {
            // Add the current element to the cumulative sum
            sum += A[i];

            // If the cumulative sum equals k, update maxLen to the current index + 1
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            // Calculate the remainder (rem) needed to reach the target sum k
            int rem = sum - k;

            // If rem is found in the map, it means there is a subarray with sum k
            // Update maxLen if this subarray is longer than previously found ones
            if (mpp.find(rem) != mpp.end()) {
                maxLen = max(maxLen, i - mpp[rem]);
            }

            // If the cumulative sum is not already in the map, store it with its index
            if (mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }

        // Return the maximum length of the subarray with sum k
        return maxLen;
    } 
};

/*
Algorithm Explanation:

Data Structures:
map<int, int> mpp: This map stores the cumulative sum as the key and the index at which this sum is first encountered as the value.

Variables:
sum: Tracks the cumulative sum of elements as we iterate through the array.
maxLen: Tracks the length of the longest subarray found so far.

Logic:
1. Iterate through the array and keep updating the cumulative sum (sum).
2. If sum equals k, then the entire subarray from the start to the current index i has the desired sum, so update maxLen accordingly.
3. Compute the remainder (rem = sum - k). If this remainder has been encountered before (exists in the map mpp), it means there is a subarray between the previous index (where this remainder was found) and the current index i that sums to k. Update maxLen if this subarray is longer than the previously found ones.
4. If sum has not been encountered before, store it in the map with its corresponding index.
*/