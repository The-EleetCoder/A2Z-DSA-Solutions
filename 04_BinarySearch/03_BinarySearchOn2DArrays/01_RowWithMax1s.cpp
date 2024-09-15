/*
https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
*/

/*
Approach to follow:

1. To solve in O(N + M) start from the top right corner of the matrix and keep track of the index of the row which has maximum 1s. 
2. Go left if you encounter 1
3. Go down if you encounter 0
4. Stop when you reach the last row or first column. 
*/

int rowWithMax1s(vector<vector<int> > arr) {
  
  int n = arr.size(); // number of rows
  int m = arr[0].size(); // number of columns

  int i=0, j=m-1, ans=-1;

  while(i<n and j>=0){
    if(arr[i][j]==1){
      ans=i;
      j--;
    }

    if(arr[i][j]==0){
      i++;
    }
  }
  return ans;
}

/*
Binary search would have resulted in a time complexity of O(n log m)
*/