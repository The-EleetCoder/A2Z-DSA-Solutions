/*
https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1
*/

class Solution {
  public:
    // Function to print numbers from 1 to N using recursion
    void printNos(int N) {
        // Base case: if N reaches 0, stop the recursion
        if (N == 0) return;
        
        // Recursive call to print numbers from 1 to N-1
        printNos(N - 1);
        
        // Print the current number N after the recursive call
        cout << N << " ";
    }
};

// We used backward recursion.
