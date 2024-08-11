/*
https://www.geeksforgeeks.org/problems/print-gfg-n-times/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-gfg-n-times
*/

// Approach 1
class Solution {
  public:
    // Helper function to print "GFG" N times using recursion
    void functionGfg(int N, int i) {
        // Base case: if i exceeds N, stop the recursion
        if (i > N) return;

        cout << "GFG" << " ";
        functionGfg(N, i + 1);
    }

    void printGfg(int N) {
        functionGfg(N, 1);
    }
};

// Approach 2
class Solution {
  public:
    void printGfg(int N) {
        // Base case: if N reaches 0, stop the recursion
        if (N == 0) return;
        
        cout << "GFG" << " ";
        
        // Recursive call with N-1
        printGfg(N-1);
    }
};

/*
Readability: The code is more concise and easier to understand without the need for an extra function.
Efficiency: Although the performance difference is minimal, eliminating an extra function call can be slightly faster, especially in large-scale recursion.
*/