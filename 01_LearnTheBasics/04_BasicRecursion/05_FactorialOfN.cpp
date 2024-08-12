/*
https://www.geeksforgeeks.org/problems/factorial5739/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
*/

class Solution{
public:
    long long int factorial(int n){
        // base case
        if (n==0 || n==1) return 1;
        
        return n * factorial(n-1);
    }
};

/*
Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }

Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
*/