/*
https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

/*
The provided code attempts to find the length of the longest subarray in arr that has a sum of zero.

Explanation:

Prefix Sum: The idea is to use the prefix sum technique. As you iterate through the array, you maintain a running sum of elements from the start of the array to the current index.

Key Observations:
If the sum from the start of the array to the current index is zero, then the subarray from the start to this index has a sum of zero.
If the same sum has been seen before at some previous index, then the elements between the previous index and the current index form a subarray with a sum of zero.

Unordered Map:
The unordered map mpp stores the first occurrence of each cumulative sum along with its index. This helps in quickly checking if the same sum has been encountered before.

Handling Edge Cases:
If the sum becomes zero at any point, the length of the subarray from the start to this index is checked and potentially updated.
If the current element itself is zero, the maxLen is updated to at least 1.

Time Complexity:
The time complexity is O(n) because the array is traversed once, and each operation involving the unordered map (insertion and lookup) is O(1) on average.

Space Complexity:
The space complexity is O(n) due to the unordered map that stores the prefix sums.
*/

int maxLen(vector<int>& arr, int n) {
    // Map to store the prefix sum and its index
    unordered_map<int, int> mpp;  
    // Variable to store the cumulative sum
    int sum = 0;  
    // Variable to store the maximum length of subarray with sum 0
    int maxLen = 0;  

    for(int i = 0; i < n; i++) {
        // Update the cumulative sum
        sum += arr[i];  

        // If the current element itself is zero, update maxLen to at least 1
        if (arr[i] == 0) {
            maxLen = max(maxLen, 1);
        }

        // If the cumulative sum becomes zero, the subarray from the start to the current index has a sum of 0
        if (sum == 0) {
            maxLen = max(maxLen, i + 1);
        }

        // If the cumulative sum has been seen before, it means the subarray between the previous index and the current index has a sum of 0
        if (mpp.find(sum) != mpp.end()) {
            maxLen = max(maxLen, i - mpp[sum]);
        } else {
            // Store the first occurrence of the cumulative sum with its index
            mpp[sum] = i;
        }
    }
    // Return the maximum length of the subarray with sum 0
    return maxLen;  
}
