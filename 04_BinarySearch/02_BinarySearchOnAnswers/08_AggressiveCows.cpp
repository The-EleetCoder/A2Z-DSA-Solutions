/*
https://www.geeksforgeeks.org/problems/aggressive-cows/1
*/

/*
The problem you're trying to solve is based on allocating cows to different stalls in such a way that the minimum distance between any two cows is maximized. It's a binary search-based solution combined with the greedy approach to check if a configuration is valid.

Intuition:
Problem Breakdown:
You have n stalls, and you want to place k cows such that the minimum distance between any two cows is maximized. The problem can be solved by checking whether it's possible to place the cows in a certain configuration, and then using binary search to find the largest possible minimum distance.

Binary Search for Optimization:
We use binary search on the minimum possible distance between cows (mid) because if it's possible to place cows with at least mid distance, it might also be possible with a larger distance. Conversely, if it's not possible with mid, then it won’t be possible with a larger distance.

Greedy Approach:
To check if a certain distance mid is possible, start placing cows from the first stall, and place the next cow only if the distance to the next stall is at least mid.
*/

class Solution {
public:

    // This function checks if it's possible to place `k` cows in the stalls
    // such that the minimum distance between any two cows is at least `mid`.
    bool isPossible(int n, int k, vector<int> &stalls, int mid) {
        int cow_count = 1; // Place the first cow in the first stall
        int current_stall = stalls[0]; // Store the position of the last placed cow
        
        // Try to place the remaining cows
        for (int i = 1; i < n; i++) {
            int difference = stalls[i] - current_stall; // Distance from the last placed cow
            
            // If the current stall is far enough from the last cow, place a new cow here
            if (difference >= mid) {
                cow_count++;
                current_stall = stalls[i]; // Update the position of the last placed cow
            }
        }
        
        // Return true if we've placed at least `k` cows, else false
        return cow_count >= k;
    }
    
    // Function to find the largest minimum distance between cows
    int solve(int n, int k, vector<int> &stalls) {
        // Sort the stall positions to allow placement with minimum distance checks
        sort(stalls.begin(), stalls.end());
        
        int start = 1; // Minimum possible distance (1 unit)
        int max_ele = stalls[n-1]; // The position of the last stall
        int end = max_ele - stalls[0]; // Maximum possible distance
        
        int ans = 1; // Variable to store the final answer
        
        // Perform binary search on the possible distances
        while (start <= end) {
            int mid = start + (end - start) / 2; // Middle value of the search space
            
            // Check if it's possible to place cows with at least `mid` distance apart
            bool possible = isPossible(n, k, stalls, mid);
            
            if (possible) {
                ans = mid; // Update the answer to the current mid
                start = mid + 1; // Try for a larger distance
            }
            else {
                end = mid - 1; // Try for a smaller distance
            }
        }
        return ans; // Return the largest minimum distance found
    }
};

/*
Explanation of Key Parts:

isPossible Function:
This function checks if it’s possible to place all k cows in the stalls such that the minimum distance between any two cows is at least mid. The cows are placed greedily: once a cow is placed in a stall, the next cow is placed in the next stall that is at least mid distance away.

solve Function:
We first sort the stalls to make sure we can place cows in increasing order of positions. Then we use binary search on the possible minimum distance between cows (starting from 1 and going up to the maximum distance between the first and last stall). For each possible distance mid, we check if placing the cows with at least that distance is feasible using the isPossible function.

Binary Search Logic:
If placing cows is possible with a certain distance mid, we move to larger distances (start = mid + 1) to maximize the minimum distance. Otherwise, we reduce the search space (end = mid - 1).

This approach ensures an efficient solution with a time complexity of O(nlogd), where d is the difference between the maximum and minimum stall positions.
*/