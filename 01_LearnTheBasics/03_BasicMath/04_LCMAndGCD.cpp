/*
https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1
*/
class Solution {
public:
    // Function to compute the Greatest Common Divisor (GCD) of two numbers using the Euclidean algorithm
    long long Gcd(long long A, long long B) {
        long long mini = min(A, B);
        long long maxi = max(A, B);
        
        // Continue the loop until the remainder becomes zero
        while (true) {
            long long rem = maxi % mini;

            // If the remainder is 0, then mini is the GCD
            if (rem == 0) return mini;

            maxi = mini;
            mini = rem;
        }
    }
  
    // Function to calculate both LCM and GCD of two numbers
    vector<long long> lcmAndGcd(long long A, long long B) {
        long long GCD = Gcd(A, B); 

        // Calculate the LCM using the relationship: LCM(A, B) * GCD(A, B) = A * B
        long long Lcm = (A * B) / GCD;

        return {Lcm, GCD};
    }
};

/*
The Euclidean algorithm is an efficient method for computing the Greatest Common Divisor (GCD) of two numbers. The GCD of two numbers is the largest number that divides both of them without leaving a remainder. The algorithm is based on the principle that the GCD of two numbers also divides their difference.

Steps of the Euclidean Algorithm:
Divide and Find Remainder: Given two numbers, A and B, where A >= B, divide A by B and find the remainder R.

                                                  A=B×Q+R

Here, Q is the quotient and R is the remainder.

Replace and Repeat: Replace A with B and B with R, and repeat the process until the remainder R is 0.

GCD Found: When the remainder R becomes 0, the current value of B (from the previous step) is the GCD of the original two numbers A and B.
*/

