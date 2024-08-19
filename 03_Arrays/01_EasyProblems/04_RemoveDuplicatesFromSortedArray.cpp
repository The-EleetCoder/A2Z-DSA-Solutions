/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/

// initial approach - Using set - TC: O(NlogN) - SC: O(N)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Create a set to store unique elements
        set <int> s;

        // Iterate over the input array
        for (int i = 0; i < nums.size(); i++) {
            // Insert each element into the set.
            s.insert(nums[i]);
        }

        // Initialize a variable 'j' to keep track of the position in the array
        int j = 0;

        // Iterate over the set (which contains only unique elements)
        for (int i : s) {
            nums[j++] = i;
        }

        // Return the size of the set, which is the number of unique elements
        return s.size();
    }
};


// optimal approach - Two pointer Approach - TC: O(N) - SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialize the pointer 'i' to track the position of the last unique element.
        int i = 0;

        // Iterate through the array starting from the second element.
        for (int j = 1; j < nums.size(); j++) {
          /*
          If the current element 'nums[j]' is not equal to the last unique element 'nums[i]',
          it means we've found a new unique element.
          */ 
            if (nums[j] != nums[i]) {
                // Move the new unique element to the position after the last unique element.
                nums[i + 1] = nums[j];
                // Increment 'i' to update the position of the last unique element.
                i++;
            }
        }

        // The length of the array without duplicates is 'i + 1'.
        return i + 1;
    }
};

