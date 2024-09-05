/*
https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
*/

/*
This function implements the logic to find the n-th root of a number m, where the goal is to find an integer x such that x^n = m. If no such integer exists, the function returns -1. The approach leverages binary search to efficiently find the solution, as the value of x lies between 0 and m / n.

Key Points of the Algorithm:

Binary Search Range:
The possible values for the n-th root of m are between 0 and m / n. This is because, for large n, the n-th root of m will be much smaller than m itself.

Binary Search Mechanism:
We apply binary search to narrow down the value of x that satisfies x^n = m. If such a value is found, we return it; otherwise, we return -1.

Edge Case:
If m == 1, the function immediately returns 1 because x^n = 1 for any x = 1.
*/

int NthRoot(int n, int m) {
    // If m is 1, return 1 since 1^n = 1 for any n
    if (m == 1) return 1;

    int start = 0;
    int end = m / n;

    // Binary search to find the n-th root of m
    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Calculate mid^n
        long long midPowerN = pow(mid, n);

        // If mid^n is equal to m, return mid as the n-th root
        if (midPowerN == m) return mid;
        
        // If mid^n is less than m, search the right half (increase mid)
        else if (midPowerN < m) {
            start = mid + 1;
        } 
        // If mid^n is greater than m, search the left half (decrease mid)
        else {
            end = mid - 1;
        }
    }
    // If no integer n-th root is found, return -1
    return -1;
}


/*
Explanation:

Initial Edge Case:
If m == 1, the result is 1 for any n, because 1^n = 1 for any n.

Binary Search:
The binary search runs between 0 and m / n.
We compute mid^n using pow(mid, n) for the current midpoint mid.
If mid^n == m, we return mid since we found the n-th root.
If mid^n < m, this means that the potential root must be larger, so we move the search to the right by setting start = mid + 1.
If mid^n > m, we move the search to the left by setting end = mid - 1.

Return -1 if No Root Found:
If no integer x satisfies x^n = m after the search, we return -1 to indicate that the n-th root of m doesn't exist as an integer.

Time Complexity:
O(log(m)): The binary search reduces the search space by half in each step, so the time complexity is logarithmic in terms of m.
*/