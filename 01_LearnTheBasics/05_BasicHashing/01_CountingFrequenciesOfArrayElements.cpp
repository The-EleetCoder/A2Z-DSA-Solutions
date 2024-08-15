/*
https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0
*/

// Approach 1 (using unordered map - TC - O(N) & SC - O(N) )
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P)
    { 
        unordered_map<int, int> mpp;
        
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

// Approach 2 ( modifying the original array TC - O(N) & SC - O(1))
class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P) {
        int i = 0;
        while(i<N){
            // if element is greater than N
            if (arr[i]>N) {
                arr[i]=0;
                i++;
                continue;
            }
            
            // if element is negative
            if (arr[i]<=0) {
                i++;
                continue;
            }

            int elementIndex = arr[i]-1; 
            // if other element is > 0 
            if (arr[elementIndex] > 0){
                arr[i] = arr[elementIndex];
                arr[elementIndex] = -1;
            }
            // if other element is <= 0
            else {
                arr[elementIndex] -= 1;
                arr[i] = 0;
                i++;
            }
        }
        
        for (int i=0; i<N;i++){
            if(arr[i] < 0) arr[i] = -arr[i];
            else arr[i]=0;
        }
    }
};