/*
https://www.geeksforgeeks.org/problems/count-digits5716/1
*/
class Solution {
public:
    // Function to count the number of digits in N that evenly divide N
    int evenlyDivides(int N) {
        int n = N, count = 0; 

        // Loop to process each digit of the number N
        while (n > 0) {
            int digit = n % 10;
            // Check if digit divides N evenly and is not zero
            if (digit != 0 && N % digit == 0) 
                count++; 
            n = n / 10;
        }
        return count;
    }
};