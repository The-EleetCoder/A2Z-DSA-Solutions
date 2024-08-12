/*
https://leetcode.com/problems/valid-palindrome/description/
*/

class Solution {
public:

    // Recursive helper function to check if the substring s[start:end] is a palindrome
    bool palindrome(int start, int end, const string& s) {
        // base case
        if (start >= end) return true;
        // Move start index to the next alphanumeric character
        if (!isalnum(s[start])) {
            return palindrome(start + 1, end, s);
        }
        // Move end index to the previous alphanumeric character
        if (!isalnum(s[end])) {
            return palindrome(start, end - 1, s);
        }
        // Compare the characters, ignoring case
        if (tolower(s[start]) != tolower(s[end])) {
            return false;
        }
        // Recursively check the next pair of characters
        return palindrome(start + 1, end - 1, s);
    }

    // Main function to check if the string is a palindrome
    bool isPalindrome(const string& s) {
        return palindrome(0, s.length() - 1, s);
    }
};