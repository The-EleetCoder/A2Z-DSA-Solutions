/*
https://leetcode.com/problems/palindrome-number/description/
*/

// Approach 1
// Converting int to string - Less optimised approach
class Solution {
public:
    bool isPalindrome(int x) {
        string str_x = to_string(x);
        int end = str_x.length()-1;
        int start = 0;

        while(start < end){
            if (str_x[start]!=str_x[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
/*
String Conversion: The code converts the integer to a string using to_string(x), which has an overhead in terms of time and space complexity. Converting an integer to a string takes O(n) time, where n is the number of digits in the integer, and it also uses extra space proportional to the length of the number.

Space Complexity: The string conversion uses additional space to store the string representation of the number, which could be avoided.
*/

// Approach 2
// Finding the reverse and then comparing (using long long)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        long long original = x; 
        long long reversed = 0; 

        while (x > 0) {
            int lastDigit = x % 10;
            reversed = reversed * 10 + lastDigit;
            x = x / 10;
        }

        // A number is a palindrome if it is equal to its reverse
        return original == reversed;
    }
};
/*
This code is correct and will work for all valid inputs. However, using long long is overkill for this problem since the input is a 32-bit integer.
The more optimal version uses regular int and includes a check to prevent overflow during the reversal process.
*/

// Approach 3 - Most optimal
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) 
            return false;

        int original = x;
        int reversed = 0;

        while (x > 0) {
            int lastDigit = x % 10;

            // Check for potential overflow before it happens
            if (reversed > (INT_MAX - lastDigit) / 10) 
                return false;

            reversed = reversed * 10 + lastDigit;
            x = x / 10;
        }

        return original == reversed;
    }
};
/*
This condition works because its given that the input would always be a valid integer, so if the input is a palindrome, then its reverse would also be a valid integer, hence while checking the range, if it goes outside the range, the function directly returns false.
*/