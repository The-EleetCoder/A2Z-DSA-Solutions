/*
https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1
*/
class Solution {
  public:
    void print_divisors(int n) {
        vector<int> largeDivisors;
        
        // Iterate from 1 to sqrt(N)
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cout << i << " "; // Print smaller divisor
                if (i != n / i) {
                    largeDivisors.push_back(n / i); // Store larger divisor
                }
            }
        }
        
        // Print the larger divisors in reverse order
        for (int i = largeDivisors.size() - 1; i >= 0; i--) {
            cout << largeDivisors[i] << " ";
        }
    }
};
