/*
https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0
*/

/*
Iterate through the array and calculate the sum of each pair of adjacent elements. 
Then, track the maximum sum encountered.
*/

class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        int max_sum = INT_MIN; // Initialize to the smallest possible integer value
        
        for(int i = 0; i < arr.size() - 1; i++) {
            int sum = arr[i] + arr[i + 1];
            if(sum > max_sum) {
                max_sum = sum;
            }
        }
        
        return max_sum;
    }
};
