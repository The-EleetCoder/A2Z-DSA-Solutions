/*
https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
*/

/*
The problem you're solving is about finding the 𝑘𝑡ℎ smallest element in the union of two sorted arrays (arr1 and arr2). The approach used here is an efficient binary search strategy that avoids merging both arrays, which would take O(n1 + n2) time, where n1 and n2 are the lengths of the arrays.
*/

class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        if (n1>n2) return kthElement(k, arr2, arr1);
        
        int start = max(0, k-n2);
        int end = min(n1, k);
        
        while (start<=end){
            int mid1 = start + (end - start)/2;
            int mid2 = k - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            if (mid1 < n1){
                r1 = arr1[mid1];
            }
            if (mid2 < n2){
                r2 = arr2[mid2];
            }
            if (mid1 - 1 >= 0){
                l1 = arr1[mid1 - 1];
            }
            if (mid2 - 1 >= 0){
                l2 = arr2[mid2 - 1];
            }
            
            if (l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1 > r2){
                end = mid1 - 1;
            }
            else {
                start = mid1 + 1;
            }
        }
        return 0;
    }
};

/*
Approach and Intuition:

The binary search algorithm leverages the fact that both arrays are sorted. Instead of merging them and sorting, you split the search space in the two arrays based on the position of the kth element. 

Here's how the algorithm works:

Size Comparison: First, you make sure arr1 is the smaller array (i.e., n1 <= n2). This simplifies the logic since you are primarily focusing on minimizing the number of elements in arr1 being searched.

Binary Search Setup:
You set up a binary search on arr1 within the valid range of elements that can contribute to the kth element. The range for arr1 is from max(0, k-n2) to min(n1, k).
max(0, k-n2): Ensures that at least k-n2 elements are considered from arr1.
min(n1, k): Ensures that you are not selecting more than n1 elements from arr1.

Partitioning the Arrays:
You pick a middle point (mid1) in arr1 and calculate the corresponding middle point (mid2) in arr2 such that the total number of elements considered from both arrays equals k. Specifically, mid2 = k - mid1.

Comparing Boundaries:
You compare the elements at the boundary of the partitions:
l1, l2 are the largest elements on the left sides of the partitions in arr1 and arr2.
r1, r2 are the smallest elements on the right sides of the partitions in arr1 and arr2.
If the conditions l1 <= r2 and l2 <= r1 hold, it means that you have found the correct partition where all elements on the left are less than or equal to all elements on the right, so the largest element on the left (max(l1, l2)) is the kth element.

Adjusting the Search:
If l1 > r2, it means the partition in arr1 is too large, so you decrease the range by moving end to mid1 - 1.
If l2 > r1, the partition in arr1 is too small, so you increase start to mid1 + 1.

Returning the Result: When the correct partition is found, the maximum of the left partition (max(l1, l2)) gives the kth smallest element.
*/