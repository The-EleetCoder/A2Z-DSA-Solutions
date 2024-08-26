/*
https://leetcode.com/problems/next-permutation/
*/

// using the inbuilt next_permutation() function
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};


/*
Algorithm / Intuition

The steps are the following:

👉 Find the break-point, i: 
Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1]. 

For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). Here from the back of the array, index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.

To find the break-point, we will use a loop to traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].

👉 If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order of all possible permutations. So, the next permutation must be the first i.e. the permutation in increasing order. So, in this case, we will reverse the whole array and will return it as our answer.

If a break-point exists:
👉 Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
👉 Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        
        // if there is only one element, return the array as it is
        if (n == 1) return;
        
        // finding the breakpoint
        int breakpoint = -1;
        for (int i = n-2; i>=0; i--){
            if (nums[i]<nums[i+1]){
                breakpoint = i;
                break;
            }
        }

        // it means that the array is in descending order
        if (breakpoint==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        // find the smallest element, that is > nums[breakpoint], on the right side of breakpoint.
        for (int i = n-1; i > breakpoint; i--){
            if (nums[i]>nums[breakpoint]){
                swap(nums[i], nums[breakpoint]);
                break;
            }
        }

        // reverse the array, right to the breakpoint 
        reverse(nums.begin()+breakpoint+1, nums.end());
    }
};