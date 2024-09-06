/*
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

/*
Problem Intuition:
The problem involves determining the minimum weight capacity of a ship required to transport packages within a given number of days. Each day, the ship can carry a weight up to the capacity, and we need to find the minimum capacity such that all packages can be shipped within the specified number of days.

Key Insights:

Binary Search on Capacity:
The minimum possible capacity is the maximum weight of a single package, since the ship must be able to carry the heaviest package on its own.
The maximum possible capacity is the sum of all package weights, which represents the case where the ship would have to carry all packages in one day.
We use binary search within this range to find the smallest capacity that allows shipping all packages within the given days.

Feasibility Check (Helper Function isPossible):
For a given capacity mid, we check if it is possible to ship all packages within days days.
We iterate through the weights and keep adding them to the current weight until adding another package would exceed mid.
If it would exceed, we increment the day count, start a new day with the current package, and continue.
Finally, we check if the number of days used is within the allowed limit.
*/

class Solution {
public:
    // Helper function to determine if it's possible to ship within 'days' with capacity 'mid'
    bool isPossible(vector<int>& weights, int days, int mid) {
        int currentWeight = 0; // Current weight in the ship
        int totalDays = 0;     // Count of days required
        
        // Iterate through each weight
        for (int i = 0; i < weights.size(); i++) {
            // If adding this weight exceeds the capacity 'mid'
            if (currentWeight + weights[i] > mid) {
                // Start a new day with the current weight
                currentWeight = weights[i]; 
                totalDays++; // Increment the day count
            } else {
                // Continue adding to the current day
                currentWeight += weights[i];
            }
        }
        
        // Check the last day if it has any remaining weight
        if (currentWeight > 0) totalDays++;
        
        // Return true if we can ship within the given days
        return (totalDays <= days);
    }

    // Main function to find the minimum ship capacity
    int shipWithinDays(vector<int>& weights, int days) {
        // Calculate the total weight and the maximum weight of a single package
        int totalWeight = accumulate(weights.begin(), weights.end(), 0);
        int maxWeight = *max_element(weights.begin(), weights.end());

        // Initialize the binary search range
        int start = maxWeight; // Minimum possible capacity
        int end = totalWeight; // Maximum possible capacity
        int ans = totalWeight; // Initialize the answer to the worst case

        // Perform binary search to find the minimum capacity
        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate the mid-point capacity

            // Check if it's possible to ship within 'days' with capacity 'mid'
            bool possible = isPossible(weights, days, mid);

            if (possible) {
                ans = mid; // Update the answer
                end = mid - 1; // Try to find a smaller capacity
            } else {
                start = mid + 1; // Increase the capacity
            }
        }

        return ans; // Return the minimum capacity found
    }
};

/*
Explanation of Key Parts:

Binary Search on Capacity:
We use binary search to efficiently find the minimum capacity. The search range is between the maximum weight of a single package (start) and the sum of all weights (end).

Helper Function (isPossible):
This function checks if a given capacity mid can handle shipping all packages within the specified number of days.
We sum weights until adding another weight exceeds the capacity, then increment the day count and start a new day.

Binary Search Loop:
If the current capacity mid can handle shipping all packages within days, we update the answer and try a smaller capacity.
If it cannot, we increase the capacity and continue searching.

Time Complexity:
Binary Search: O(log(totalWeight - maxWeight)) for narrowing down the possible capacities.
Feasibility Check: O(n) for checking each mid-point, where n is the number of weights.
Overall Time Complexity: O(n log(totalWeight)).
*/