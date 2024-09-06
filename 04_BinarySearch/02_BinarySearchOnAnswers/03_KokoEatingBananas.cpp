/*
https://leetcode.com/problems/koko-eating-bananas/
*/

/*
This problem involves Koko trying to eat all the bananas in different piles within a given number of hours. The goal is to find the minimum speed (bananas per hour) at which Koko should eat to finish all the piles within the given time. The intuition behind solving this problem involves binary search over the potential eating speeds.
*/

class Solution {
public:
    // Helper function to check if it's possible to finish all piles within h hours at speed mid
    bool isPossible(vector<int>& piles, int h, int mid) {
        long long int totalHours = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalHours +=  ceil( (double)piles[i] / (double)mid);
        }
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int start = 1;
        int end = maxPile;
        int ans = maxPile;

        // Perform binary search to find the minimum eating speed
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Check if it's possible to finish all piles at speed 'mid'
            if (isPossible(piles, h, mid)) {
                ans = mid;         // Update the answer with the current 'mid'
                end = mid - 1;     // Try to find a smaller speed in the left half
            } else {
                start = mid + 1;   // Increase the speed and search the right half
            }
        }
        return ans;  // Return the minimum speed found
    }
};

/*
Key Concepts:

Binary Search on Speed:
The speed at which Koko eats can range from 1 banana per hour to the size of the largest pile.
We want to find the minimum speed at which she can finish all the bananas within h hours.
This makes it a good candidate for binary search, where we progressively narrow down the range of possible speeds.

Feasibility Check (Helper Function isPossible):
For a given speed mid, we need to check if Koko can finish all the piles in h hours.
We iterate over the piles and calculate how many hours it would take to finish each pile at speed mid.
If the total hours for all piles is less than or equal to h, it means the speed is feasible.

Binary Search Approach:
Initialize the search with the minimum possible speed (start = 1) and the maximum possible speed (end = max(piles)).
For each mid-point (mid = (start + end) / 2), check if it's possible to finish the bananas at that speed using the isPossible function.
If the speed is feasible, update the answer (ans) and try to find a smaller speed (left half).
If it's not feasible, increase the speed (right half) by moving start.

Steps:
Initialize Search: Start with start = 1 (minimum speed) and end = maxPile (maximum speed).
Binary Search: In each iteration, check the mid-point speed:
If it's feasible (isPossible returns true), update the answer and search the left half.
If it's not feasible, search the right half.

Return the Answer: 
After the search ends, the answer will contain the minimum speed that allows Koko to eat all the bananas within the given hours.

Why Binary Search?
Instead of checking all possible speeds from 1 to the size of the largest pile, which would be inefficient (linear search), binary search reduces the time complexity significantly to O(n log m), where n is the number of piles and m is the largest pile size.
*/