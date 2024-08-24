/*
https://leetcode.com/problems/majority-element/
*/

/*
Intuition:
The given code solves the "Majority Element" problem, where the goal is to find the element that appears more than half the time in the array. The solution leverages the fact that if an element appears more than n/2 times in a sorted array, it must occupy the middle position.

TC: O(nlogn) 
SC: O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};


/*
The given code solves the "Majority Element" problem by using a hash map to count the occurrences of each element in the array. The algorithm then checks which element has a count greater than half the size of the array (n/2). The element that satisfies this condition is returned as the majority element.

TC: O(n)
SC: O(n)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mpp; 
        int n = nums.size();

        // Step 1: Count the occurrences of each element in the array and store in map
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++; 
        }

        // Step 2: Iterate through the map to find the majority element
        for (auto i : mpp) {
            if (i.second > n / 2) {
                return i.first;
            }
        }
        
        return -1;
    }
};


/*
The "Majority Element" problem can be solved in linear time (O(N)) and with constant space (O(1)) using the Boyer-Moore Voting Algorithm. This algorithm is particularly efficient and elegant for this problem.

Intuition:
The Boyer-Moore Voting Algorithm works by maintaining a candidate for the majority element and a counter to track the balance between the candidate and other elements. The algorithm makes a single pass over the array, updating the candidate and the counter based on the elements encountered.

Key Concepts:

👉 Candidate Selection:
The algorithm assumes the first element to be the majority candidate and initializes a counter to 1.
As it iterates through the array, it either increments the counter if the current element matches the candidate or decrements the counter if it does not.

👉 Counter Reset:
If the counter reaches zero, the algorithm resets the candidate to the current element and sets the counter to 1.
The idea is that the majority element, which appears more than half the time, will eventually dominate the counter and emerge as the candidate.

👉 Guaranteed Majority:
By the end of the array, the candidate will be the majority element because any minority elements would have canceled out.

👉 Steps:
Initialize candidate as the first element and count as 1.
Iterate through the array, updating the candidate and count based on the current element.
Return the candidate as the majority element.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];  // Initial candidate for majority element
        int count = 1;  // Initial count for the candidate

        // Step 1: Find the candidate for the majority element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                count++;  // Increment count if the current element matches the candidate
            } else {
                count--;  // Decrement count if it does not match
                if (count == 0) {
                    candidate = nums[i];  // Change the candidate
                    count = 1;  // Reset the count
                }
            }
        }

        // The candidate is the majority element
        return candidate;
    }
};