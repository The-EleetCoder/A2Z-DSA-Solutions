/*
https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1
*/

// Using Binary Search
class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int searchInSorted(int arr[], int N, int k) {
        int start = 0;
        int end = N-1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            if (arr[mid] == k) return 1;
            else if (arr[mid] > k){
                end = mid - 1; 
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
};