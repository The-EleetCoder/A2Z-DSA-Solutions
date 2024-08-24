/*
https://leetcode.com/problems/sort-colors/
*/

/*
The given code solves the "Sort Colors" problem, where the goal is to sort an array nums containing only three distinct integers: 0, 1, and 2. This is a variant of the Dutch National Flag problem. The algorithm counts the occurrences of each color (0, 1, 2) and then reconstructs the array by placing the counted numbers in order. The code uses a map to store the frequency of each color and then overwrites the original array based on these frequencies.

Step-by-Step Intuition:
👉 Counting Frequencies:
The first step is to count how many 0s, 1s, and 2s are present in the array. This is done using a map (mpp), where the keys are the colors (0, 1, 2), and the values are their counts.

👉 Reconstructing the Array:
After counting, the algorithm reconstructs the sorted array. It first fills in all the 0s, then all the 1s, and finally all the 2s based on the counts stored in the map.

👉 Efficiency:
The algorithm runs in O(N) time where N is the size of the array. The counting step takes O(N), and the reconstruction step also takes O(N). The space complexity is O(1) extra space if we consider that the map has a fixed size since there are only three distinct elements (0, 1, 2).
*/

// initial approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mpp; // Map to store the count of each color (0, 1, 2).
        
        // Step 1: Count the occurrences of each color.
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++; // Increment the count of the current color.
        }
        
        int n = nums.size();
        int i = 0; // Index to place the sorted colors in the array.
        
        // Step 2: Place all the 0's in the array based on their count.
        int j = 0;
        while (i < n && j < mpp[0]) { 
            nums[i++] = 0;
            j++;
        }

        // Step 3: Place all the 1's in the array based on their count.
        j = 0;
        while (i < n && j < mpp[1]) {
            nums[i++] = 1;
            j++;
        }

        // Step 4: Place all the 2's in the array based on their count.
        j = 0;
        while (i < n && j < mpp[2]) {
            nums[i++] = 2;
            j++;
        }
    }
};


/*
The given algorithm can be optimized both in terms of time and space. The current approach uses a map to count the occurrences of 0, 1, and 2, and then reconstructs the array. While this is efficient in O(N) time, it uses extra space for the map. The problem can be solved using an in-place algorithm that doesn't require extra space, leading to an even more efficient solution.

👉 Optimized Approach: Dutch National Flag Algorithm

The Dutch National Flag problem, proposed by Edsger Dijkstra, provides an optimal solution to sort an array of 0s, 1s, and 2s in a single pass (O(N) time complexity) with constant space (O(1) space complexity). The idea is to maintain three pointers (low, mid, and high) to categorize the elements as follows:

-> low pointer: This points to the boundary where all elements before low are 0s.
-> mid pointer: This traverses the array, and elements before mid are either 0s or 1s.
-> high pointer: This points to the boundary where all elements after high are 2s.

Steps:

👉 Initialization:
low = 0, mid = 0, high = n - 1 (where n is the size of the array).

👉 Traversal:
Traverse the array with the mid pointer:
If nums[mid] == 0: Swap nums[low] with nums[mid], increment both low and mid.
If nums[mid] == 1: Just move the mid pointer.
If nums[mid] == 2: Swap nums[mid] with nums[high], decrement high.

👉 Termination:
The loop terminates when mid exceeds high. At this point, the array is sorted.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        // Traverse the array
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
                // Don't move mid forward since the swapped element could be 0 or 1
            }
        }
    }
};
