/*
https://leetcode.com/problems/kth-missing-positive-number/
*/

/*
This solution finds the k-th missing positive integer in a sorted array using binary search.
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size() - 1;

        // Perform binary search
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int missing = arr[mid] - (mid + 1); // Calculate missing numbers till this index

            if (missing < k) {
                // If missing numbers so far are less than k, search in the right half
                start = mid + 1;
            } else {
                // Otherwise, search in the left half
                end = mid - 1;
            }
        }

        // After binary search, 'start' is the index where k-th missing number should be
        return start + k;
    }
};

/*
Key Idea:

Given a sorted array arr, some integers are missing from the sequence of positive numbers. For example, if arr = [2, 3, 4, 7, 11], the missing numbers before the first element are 1, after the first element are 5, 6, and so on.

We want to find the k-th missing positive integer, and the problem is that as the array grows, missing numbers appear sporadically. To efficiently search for the k-th missing number, binary search is used.

Explanation:
Tracking Missing Numbers: At any index mid of the array arr, the number of missing positive integers before arr[mid] is given by:
missing=arr[mid]−(mid+1)

This formula works because:
In a perfect sequence, the mid-th index should have contained the number mid + 1 if no numbers were missing.
If arr[mid] is larger than mid + 1, it means some numbers before arr[mid] are missing. The difference between arr[mid] and mid + 1 tells how many numbers are missing up to that point.

Binary Search Logic:
If the count of missing numbers up to arr[mid] is less than k, it means the k-th missing number must be in the right half of the array, so we adjust the search range to the right (start = mid + 1).
If the count of missing numbers is greater than or equal to k, the k-th missing number could be in the left half, so we adjust the search range to the left (end = mid - 1).
Final Calculation: After the binary search completes, the value of start will be the index where the k-th missing number should be. Since arr contains the actual numbers and skips some, the result is found by adding k to start (i.e., start + k).

Example Walkthrough:
For arr = [2, 3, 4, 7, 11] and k = 5:

At mid = 2 (where arr[2] = 4), the number of missing integers before 4 is 4 - (2 + 1) = 1. Since 1 < 5, search moves to the right.

At mid = 4 (where arr[4] = 11), the number of missing integers before 11 is 11 - (4 + 1) = 6. Since 6 > 5, search moves to the left.

At the end of binary search, start = 4, and the answer is start + k = 4 + 5 = 9.

Thus, the 5th missing number is 9.
*/