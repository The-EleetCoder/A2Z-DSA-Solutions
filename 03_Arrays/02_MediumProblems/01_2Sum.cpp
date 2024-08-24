/*
https://leetcode.com/problems/two-sum/
*/

// Brute Force approach - TC: O(N^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> arr;
        for (int i=0;i<nums.size()-1;i++){
            for (int j=i+1;j<nums.size();j++){
                if (nums[i]+nums[j]==target){
                    arr.push_back(i);
                    arr.push_back(j);
                    break;
                }
            }
        }
        return arr;
    }
};


// Optimal approach - Using Map - TC: O(N) - SC: O(N) 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        map<int, int> mpp; // Map to store the value and its index.

        // Iterate through the array to find the two numbers that sum to the target.
        for (int i = 0; i < nums.size(); i++) {

            // Check if the complement (target - current number) exists in the map.
            if (mpp.find(target - nums[i]) != mpp.end()) {
          
                // If found, push the indices of the complement and the current number to the result vector.
                arr.push_back(mpp[target - nums[i]]);
                arr.push_back(i);
                break; // Since the problem guarantees only one solution, we can break out of the loop.
            } else {

                // If the complement is not found, store the current number and its index in the map.
                mpp[nums[i]] = i;
            }
        }
        return arr;
    }
};


/*
The intuition behind the twoSum algorithm is to efficiently find two numbers in an array that add up to a given target sum. The key idea is to use a hash map (or unordered_map in C++) to store the numbers we've seen so far along with their indices. This allows us to quickly check if the complement of the current number (i.e., target - nums[i]) exists in the array without needing a nested loop, thereby reducing the time complexity to O(N).

Step-by-Step Intuition:

👉 Complement Concept:
For each number in the array, the algorithm calculates its complement with respect to the target sum, i.e., complement = target - current_number.
If two numbers add up to the target, one number is the complement of the other.

👉 Using a Hash Map for Fast Lookups:
The algorithm uses a hash map (mpp) to store each number along with its index as we iterate through the array.
The map allows us to check in constant time (O(1)) whether the complement of the current number has already been encountered.

👉 Early Exit:
As soon as the algorithm finds a pair of numbers whose sum equals the target, it stores their indices and breaks out of the loop. This early exit is possible because the problem guarantees exactly one solution, making further checks unnecessary.
*/
