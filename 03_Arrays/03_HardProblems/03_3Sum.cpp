/*
https://leetcode.com/problems/3sum/
*/

/*
find all unique triplets in the array nums that sum up to zero.
brute force - gives TLE
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> st;
    int n = nums.size();

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    }
};


/*
Better Solution - Still gives TLE

This code is an optimized approach to the three-sum problem. Instead of using three nested loops to check all possible triplets, it uses a hash set to check if the third element needed to make the sum zero exists in the array.

Intuition:
Problem Context: The task is to find all unique triplets in the array nums that sum up to zero.

Two-Pointer Approach with a Hash Set:
First Element Selection: The outer loop iterates through each element in nums as the first element of the triplet.

Hash Set for the Second Element: The inner loop iterates over the array starting from the next element, using a hash set to keep track of the elements seen so far.

Third Element Calculation: For each pair of elements (nums[i], nums[j]), it calculates the third element (third) that would make the sum of the triplet zero. If this third element is already in the hash set, it means that a valid triplet has been found.

Handling Duplicates: The triplet is sorted and added to a set to automatically handle duplicates.

Efficiency:
Time Complexity: The time complexity of this approach is O(n^2 * logK) because, for each element, the inner loop runs in O(n), and inserting into the set requires O(logK), where K is the number of unique triplets found.
Space Complexity: The space complexity is O(n) due to the hash set used for storing the elements seen so far.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> st;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(nums[i] + nums[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    }
};


/*
Optimal solution
This implementation of the threeSum function uses the two-pointer technique combined with sorting to efficiently find all unique triplets in the array nums that sum to zero. This approach is optimal and avoids unnecessary computations. 

Intuition and Explanation:

Sorting: The first step is to sort the array. This allows the use of the two-pointer technique, which is efficient in finding pairs that sum to a specific value.

Outer Loop: The outer loop iterates through each element nums[i] as the first element of the triplet.

Skip Duplicates: If the current element is the same as the previous one, it is skipped to avoid duplicate triplets.
Two-Pointer Technique:

Initialization: The left pointer j is initialized to the element right after i, and the right pointer k is initialized to the last element.

Finding Triplets:
If the sum of nums[i] + nums[j] + nums[k] is greater than zero, the right pointer is moved to the left to reduce the sum.
If the sum is less than zero, the left pointer is moved to the right to increase the sum.
If the sum is exactly zero, a valid triplet is found, and both pointers are moved to find the next potential triplet while skipping duplicates.

Avoiding Duplicates:
After finding a valid triplet, both the left and right pointers are moved to the next different elements to avoid adding duplicate triplets to the result.

Time Complexity: The time complexity of this approach is O(n^2), where n is the number of elements in the array. This is optimal for this problem.
Space Complexity: The space complexity is O(1) beyond the space used to store the output, as the sorting is done in-place.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Result vector to store the triplets
        vector<vector<int>> ans;  
        int n = nums.size();
        
        // Sort the array to enable the two-pointer approach
        sort(nums.begin(), nums.end());  

        for (int i = 0; i < n; i++) {
            // Skip duplicate elements for the first element of the triplet
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;  // Left pointer
            int k = n - 1;  // Right pointer

            // Two-pointer approach to find two elements that sum with nums[i] to zero
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0) {
                    // If the sum is greater than zero, we need a smaller sum, move the right pointer
                    k--;
                } else if (sum < 0) {
                    // If the sum is less than zero, we need a larger sum, move the left pointer
                    j++;
                } else {
                    // If the sum is zero, we found a valid triplet
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);

                    // Move both pointers to the next different elements to avoid duplicates
                    j++;
                    k--;

                    // Skip duplicates for the left pointer
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    // Skip duplicates for the right pointer
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;  // Return the list of all unique triplets
    }
};
