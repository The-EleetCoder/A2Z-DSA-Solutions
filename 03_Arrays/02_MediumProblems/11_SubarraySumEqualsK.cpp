/*
https://leetcode.com/problems/subarray-sum-equals-k/
*/

/*
Intuition:

Cumulative Sum Approach:
The core idea is to use a cumulative sum to represent the sum of elements from the start of the array up to a certain index. This allows us to efficiently calculate the sum of any subarray using the difference between cumulative sums.

Mapping Cumulative Sums:
A hash map (mpp) is used to store the frequency of cumulative sums encountered during the traversal of the array. This helps in quickly checking if a subarray with a sum of k exists.

Checking for Subarrays:
For each element in the array:
1. We update the cumulative sum (sum).
2. If sum itself equals k, it means the subarray from the start to the current index has a sum of k, so we increment the count.
3. If sum - k exists in the map, it means there is a subarray ending at the current index whose sum equals k. The value of mpp[sum - k] gives the number of such subarrays, and we add this to count.
4. Finally, we update the map with the current cumulative sum.

Efficiency:
Time Complexity: O(n) since we are traversing the array only once.
Space Complexity: O(n) for the hash map storing cumulative sum frequencies.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Step 1: Create a map to store the cumulative sum frequencies
        map<int, int> mpp;

        int count = 0;
        int sum = 0;

        // Step 2: Traverse through the array
        for (int i = 0; i < nums.size(); i++) {
            // Add the current element to the cumulative sum
            sum += nums[i];

            // Step 3: If the cumulative sum is equal to k, increment the count
            if (sum == k) count++;

            /*
            Step 4: If (sum - k) exists in the map, it means there is a subarray ending at index i 
            which has a sum equal to k. We add the frequency of (sum - k) to the count.
            */
            if (mpp.find(sum - k) != mpp.end()) {
                count += mpp[sum - k];
            }

            // Step 5: Increment the frequency of the cumulative sum in the map
            mpp[sum]++;
        }

        // Step 6: Return the total count of subarrays with sum equal to k
        return count;
    }
};
