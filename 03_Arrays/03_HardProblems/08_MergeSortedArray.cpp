/*
https://leetcode.com/problems/merge-sorted-array/
*/

/*
Intuition:

-> The goal is to merge two sorted arrays, nums1 and nums2, into a single sorted array.
-> nums1 is supposed to have enough space to hold elements of both arrays, so the merge is performed in-place.
-> However, in this approach, instead of merging in-place directly into nums1, a new vector ans is created to store the merged result.
-> Two pointers, i and j, are used to traverse through nums1 and nums2 respectively.
->The smallest element between the current elements of nums1 and nums2 is chosen to be added to ans.
->Once one of the arrays is exhausted, any remaining elements from the other array are added to ans.
->Finally, nums1 is overwritten with the merged and sorted elements from ans.

This method is straightforward but has a higher space complexity due to the creation of the ans vector. It can be optimized further by merging directly into nums1 from the back.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> ans;
        int i = 0;
        int j = 0;

        while(i<m && j<n){
            if (nums1[i]<=nums2[j]) ans.push_back(nums1[i++]);
            else ans.push_back(nums2[j++]);
        }

        while(i<m){
            ans.push_back(nums1[i++]);
        }
        while(j<n){
            ans.push_back(nums2[j++]);
        }

        nums1 = ans;
    }
};


/*
Intuition:

The idea behind this approach is to merge the two arrays in place, starting from the end. This avoids the need for additional space, making the solution more efficient in terms of space complexity.

We use three pointers:
i points to the last valid element in nums1 (before the reserved space for merging).
j points to the last element in nums2.
k points to the last position in nums1, where the next largest element should be placed.

By comparing the elements from the end of both arrays, we can place the largest element at the current position k in nums1.
After placing an element, we decrement the corresponding pointer (i, j, or k).
If there are any remaining elements in nums2, they are copied directly to nums1 (since nums1's elements are already in place if i >= 0).

This approach ensures that the merge is done in O(m + n) time with O(1) additional space, making it optimal for in-place merging.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Initialize pointers for nums1 and nums2, starting from the last element of the valid ranges
        int i = m - 1;
        int j = n - 1;
        // Pointer to place elements in the correct position in nums1, starting from the end
        int k = m + n - 1;

        // Merge the two arrays from the end to the beginning
        while (i >= 0 && j >= 0) {
            // Compare the elements from the end of nums1 and nums2
            // Place the larger element at the correct position(k) in nums1
            if (nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--]; 
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If there are remaining elements in nums1, they are already in place, so no need to move them

        // If there are remaining elements in nums2, copy them to nums1
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
