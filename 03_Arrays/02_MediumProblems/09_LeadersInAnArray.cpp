/*
https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
*/

/*
Understanding Leaders in an Array:

A leader in an array is defined as an element that is greater than or equal to all the elements to its right. The rightmost element is always a leader because there are no elements to its right.
Approach:

👉 Traverse from Right to Left:
The idea is to traverse the array from the right end towards the left. We start by considering the rightmost element as the first leader (current_max), since there are no elements to compare it with on its right.

👉 Comparison with Current Maximum:
As we move leftward, we compare each element with the current maximum (current_max). If an element is greater than or equal to current_max, it is a leader. We update current_max to this new leader.

👉 Reversing the Order:
Since we are traversing from right to left, the leaders are stored in reverse order in the result vector. Therefore, we reverse the vector at the end to get the leaders in the order they appear in the array.

👉 Efficiency:
This approach efficiently finds the leaders in a single pass through the array, making it an 𝑂(𝑛)
O(n) solution in terms of time complexity. The space complexity is 𝑂(𝑛)
O(n) due to the storage of leaders in a vector.
*/

class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        // Initialize a vector to store the leaders
        vector<int> ans;
        
        // The rightmost element is always a leader, so we start by adding it to the answer
        int current_max = arr[n-1];
        ans.push_back(current_max);
        
        // Traverse the array from right to left (excluding the last element already considered)
        for (int i = n-2; i >= 0; i--) {
            /*
            If the current element is greater than or equal to the current_max,
            it is a leader, so update current_max and add it to the answer
            */ 
            if (arr[i] >= current_max) {
                current_max = arr[i];
                ans.push_back(current_max);
            }
        }
        
        // The leaders were added in reverse order, so we reverse the vector to maintain the correct order
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
