/*
https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0
*/

// Approach 1 - using map ( TC: O(nlogn))
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P)
    { 
        map<int, int> mpp;
        
        // Counting frequencies of elements in the range [1, N]
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= N) {
                mpp[arr[i]]++;
            }
        }
        
        // Updating the array with the frequency of elements from 1 to N
        for (int i = 0; i < N; i++) {
            arr[i] = mpp[i + 1];
        }
    }
};

// Approach 2
