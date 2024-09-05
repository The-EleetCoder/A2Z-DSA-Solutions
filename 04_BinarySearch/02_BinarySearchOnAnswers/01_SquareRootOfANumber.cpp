/*
https://www.geeksforgeeks.org/problems/square-root/0
*/

/*
This code implements the logic to find the integer square root of a number n (i.e., the largest integer x such that x^2 ≤ n). The approach uses binary search to efficiently calculate the floor value of the square root of a number. Let me explain the intuition behind the algorithm and provide comments for clarity.

Explanation of the Algorithm:
The square root of a number n lies between 0 and n/2 (since sqrt(n) can never be more than n/2 for n > 1).
We use binary search to find the largest integer x such that x * x ≤ n. If x * x == n, we return x as the exact square root. If x * x < n, we keep track of the largest x for which this is true.
The search continues by narrowing the range until we find the largest possible x where x^2 is less than or equal to n.
*/

long long int floorSqrt(long long int n) {
    // Edge case: The square root of 1 is 1
    if (n == 1) return 1;

    long long int start = 0;
    long long int end = n / 2;
    long long int ans = INT_MIN;
    
    // Binary search to find the floor of the square root
    while (start <= end) {
        long long int mid = start + (end - start) / 2;
        
        if (mid * mid == n) return mid;
        
        // If mid*mid is less than n, we store mid as the potential answer
        // and move to the right half (search for a larger potential answer)
        else if (mid * mid < n) {
            ans = max(ans, mid);
            start = mid + 1;
        }
        // If mid*mid is greater than n, we move to the left half
        else {
            end = mid - 1;
        }
    }

    return ans;
}
