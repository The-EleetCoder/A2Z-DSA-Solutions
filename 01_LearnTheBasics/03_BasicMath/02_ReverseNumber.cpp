/*
https://leetcode.com/problems/reverse-integer/
*/
class Solution {
public:
    int reverse(int x) {
        int num = abs(x);
        int ans = 0;
        
        while (num > 0) {
            int lastDigit = num % 10;  // Extract the last digit of num.
            
            // Check if multiplying ans by 10 would stay within 32-bit integer bounds.
            if (ans >= INT_MIN / 10 && ans <= INT_MAX / 10) {
                ans = 10 * ans + lastDigit;
            } else {
                return 0;
            }
            
            num = num / 10;  // Remove the last digit from num.
        }
        
        // If the original number was negative, negate the result.
        if (x < 0) return ans * -1;
        return ans;
    }
};
