/*
https://www.geeksforgeeks.org/problems/second-largest3735/1
*/

// Initial Approach
class Solution {
  public:
    int print2largest(vector<int> &arr) {
        
        // find maximum
        int maxi = 0;
        for (int i=0;i<arr.size();i++){
            if (arr[i]>maxi) {
                maxi = arr[i];
            }
        }
        
        // find second maximum
        int maxiTwo = 0;
        for (int i=0;i<arr.size();i++){
            if (arr[i]>maxiTwo && arr[i]!=maxi) {
                maxiTwo = arr[i];
            }
        }
        
        // if there is no second max element, return -1
        if (maxiTwo == 0) return -1;
        
        return maxiTwo;
    }
};

// optimal approach
int secondLargest(int arr[],int n) {
	
  if(n < 2) return -1;
    
  int large = INT_MIN, second_large = INT_MIN;
  
  int i;
    for (i = 0; i < n; i++) {
        if (arr[i] > large) {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }
    return second_large;                
}