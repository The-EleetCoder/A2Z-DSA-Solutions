/*
https://leetcode.com/problems/majority-element-ii/
*/

// initial approach - using map
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> ans;
        unordered_map <int,int> mpp;
        int n = nums.size();

        // mapping elements with their frequencies 
        for (int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        // adding elements whose freq > n/3
        for (auto it : mpp){
            if (it.second > n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};


/*
This code implements the Boyer-Moore Voting Algorithm to find all elements in the input vector nums that appear more than n/3 times, where n is the size of nums. The algorithm is efficient, operating in O(n) time and O(1) space.

Intuition:

Problem Context: The task is to find all elements in the array that appear more than n/3 times. There can be at most two such elements.

Boyer-Moore Voting Algorithm:
The algorithm maintains two potential candidates (element_1 and element_2) and their corresponding counts (counter_1 and counter_2).
If the count of a candidate drops to zero, it gets replaced by the current element unless the element is the other candidate.
In the first pass, the algorithm identifies the most frequent elements, and in the second pass, it confirms whether these elements actually appear more than n/3 times.

Two Passes:
First Pass: Identifies two potential candidates that could be majority elements.
Second Pass: Verifies the actual counts of these candidates to ensure they meet the required threshold (> n/3).
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;

        // Initialize counters and candidate elements
        int counter_1 = 0, counter_2 = 0;
        int element_1 = INT_MIN, element_2 = INT_MIN;

        // First pass: Identify potential majority elements
        for (int i = 0; i < nums.size(); i++) {
            if (counter_1 == 0 && nums[i] != element_2) {
                // If counter_1 is 0 and the current element is not element_2, 
                // set element_1 to the current element and reset counter_1
                counter_1++;
                element_1 = nums[i];
            } 
            else if (counter_2 == 0 && nums[i] != element_1) {
                // If counter_2 is 0 and the current element is not element_1, 
                // set element_2 to the current element and reset counter_2
                counter_2++;
                element_2 = nums[i];
            } 
            else if (nums[i] == element_1) {
                // If the current element matches element_1, increment counter_1
                counter_1++;
            } 
            else if (nums[i] == element_2) {
                // If the current element matches element_2, increment counter_2
                counter_2++;
            } 
            else {
                // If the current element matches neither, decrement both counters
                counter_1--;
                counter_2--;
            }
        }

        // Second pass: Validate the potential majority elements
        int count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == element_1) count1++;
            if (nums[i] == element_2) count2++;
        }

        // Add the valid majority elements to the answer vector
        if (count1 > nums.size() / 3) ans.push_back(element_1);
        if (count2 > nums.size() / 3) ans.push_back(element_2);
        
        return ans;
    }
};