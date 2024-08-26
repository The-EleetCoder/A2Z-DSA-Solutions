/*
https://leetcode.com/problems/longest-consecutive-sequence/
*/

/*
Intuition (initial approach):

👉 Understanding the Problem:
The goal is to find the longest consecutive sequence of integers in the array. For example, in the array [100, 4, 200, 1, 3, 2], the longest consecutive sequence is [1, 2, 3, 4].

👉 Sorting for Simplification:
By sorting the array, consecutive elements naturally appear next to each other. This allows us to traverse the array once to count the length of consecutive sequences.

👉 Two-Pointer Technique:
1. Pointers:
We use two pointers, p1 and p2, to traverse the array. p1 points to the start of the current sequence, and p2 moves forward to find the next element in the sequence.

2. Consecutive Elements:
If the difference between nums[p2] and nums[p1] is 1, the elements are consecutive, so we increase the current_length.

3. Handling Duplicates:
If the difference is 0, it means there are duplicate elements, so we move both pointers forward without altering the sequence length.

4. Breaking the Sequence:
If the difference is greater than 1, it means the sequence is broken. We then update the max_length and reset the current_length to 1.

5. Final Check:
After the loop, we perform one final check to ensure that the last sequence is considered when determining the maximum sequence length.

👉 Efficiency:
Time Complexity: o(𝑛log⁡𝑛) due to sorting the array.
Space Complexity: O(1) if we don't consider the space used by the sorting algorithm.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Sort the array to bring consecutive elements next to each other
        sort(nums.begin(), nums.end());

        // Edge case: If the array is empty, return 0 as there is no consecutive sequence
        if (nums.size() == 0) return 0;

        // Initialize two pointers and variables to track the maximum and current sequence lengths
        int p1 = 0;
        int p2 = 1;
        int max_length = 1;
        int current_length = 1;

        // Step 2: Traverse the sorted array to find the longest consecutive sequence
        while (p2 < nums.size()) {
            /*
            If the difference between the current and previous element is exactly 1,
            it means the sequence is consecutive, so increment the current sequence length
            */
            if (nums[p2] - nums[p1] == 1) {
                current_length++;
            }
            /*
            If the difference is 0, it means there is a duplicate element.
            Move both pointers forward without changing the sequence length
            */
            else if (nums[p2] - nums[p1] == 0) {
                p1++;
                p2++;
                continue;
            }
            /*
            If the difference is greater than 1, the sequence has been broken.
            Update the maximum sequence length if needed and reset the current sequence length
            */
            else {
                max_length = max(max_length, current_length);
                current_length = 1;
            }

            // Move both pointers forward
            p1++;
            p2++;
        }

        // After the loop, check one last time if the current sequence length is the maximum
        max_length = max(max_length, current_length);

        // Return the maximum sequence length found
        return max_length;
    }
};


/*
Optimal Approach Intuition:

Using a Hash Set for O(1) Lookups:
We store all the elements in a hash set to facilitate quick lookups. This allows us to efficiently determine whether a number exists in the set.

Identifying Sequence Starts:
For each element in the array, we check whether it is the start of a sequence. This is done by verifying if num - 1 exists in the set. If it doesn’t, the current number (num) is the start of a sequence.

Counting the Length of the Sequence:
Once we identify the start of a sequence, we continue checking for the next consecutive numbers (num + 1, num + 2, etc.) until the sequence is broken.
We keep track of the length of this sequence and update the max_length if this sequence is the longest we've found so far.

Efficiency:
Time Complexity: O(n) because each number is processed at most twice (once when checking if it is the start of a sequence and once when extending the sequence).
Space Complexity: O(n) for storing the elements in the hash set.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Edge case: If the array is empty, return 0 as there is no consecutive sequence
        if (nums.empty()) return 0;
        
        // Step 1: Insert all elements into a hash set for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        int max_length = 0;

        // Step 2: Iterate over each element in the array
        for (int num : nums) {
            // Check if the current number is the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int current_num = num;
                int current_length = 1;

                // Check the next consecutive numbers in the sequence
                while (numSet.find(current_num + 1) != numSet.end()) {
                    current_num++;
                    current_length++;
                }

                // Update the maximum length found
                max_length = max(max_length, current_length);
            }
        }

        // Return the maximum length of the consecutive sequence
        return max_length;
    }
};
