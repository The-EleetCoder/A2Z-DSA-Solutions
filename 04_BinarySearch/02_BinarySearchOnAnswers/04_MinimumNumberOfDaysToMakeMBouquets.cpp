/*
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
*/

/*
Problem Intuition:
The problem requires determining the minimum number of days after which Koko can make at least m bouquets, where each bouquet requires k consecutive flowers to bloom. The flowers take different amounts of time to bloom, represented by the bloomDay array.

The goal is to figure out the minimum number of days (let's call it mid) such that there are at least m bouquets of k consecutive flowers that have bloomed by day mid.

Key Insights:

Binary Search on Days:
The number of days needed to achieve the required number of bouquets can be found using binary search over a range of days, where the lower bound (start) is the earliest bloom day and the upper bound (end) is the latest bloom day.
For each midpoint (mid) in this range, we check if it's possible to make at least m bouquets by day mid.

Feasibility Check (Helper Function isPossible):
For a given day mid, we check if it's possible to collect at least m bouquets of k consecutive flowers.
As we iterate through the bloomDay array, we count consecutive flowers that have bloomed (those that have bloomed by day mid).
When we hit a day where the flower hasn't bloomed, we reset the consecutive flower count and accumulate the number of bouquets formed so far.
If at any point the total number of bouquets formed is greater than or equal to m, the day 'mid' is feasible.

Binary Search Approach:
Start: The earliest possible bloom day (min(bloomDay)).
End: The latest possible bloom day (max(bloomDay)).
For each midpoint day (mid), check if it's possible to gather at least m bouquets of k flowers. If so, try to reduce the number of days (move towards the left half), else increase the number of days (move towards the right half).
*/

class Solution {
public:
    // Helper function to check if it's possible to make 'm' bouquets of 'k' consecutive flowers by day 'mid'
    bool isPossible(vector<int>& bloomDay, int m, int k, int mid){
        int consecutiveFlowers = 0; // Tracks consecutive bloomed flowers
        int totalBouquets = 0;      // Tracks total number of bouquets made
        
        // Loop through each bloom day
        for (int i = 0; i < bloomDay.size(); i++){
            if (bloomDay[i] <= mid){ // Flower has bloomed by day 'mid'
                consecutiveFlowers++;
            }
            else {
                // Check how many bouquets can be formed from the consecutive flowers
                totalBouquets += consecutiveFlowers / k;
                consecutiveFlowers = 0; // Reset for the next batch of flowers
            }
        }
        
        // After loop, check for any remaining consecutive flowers
        totalBouquets += consecutiveFlowers / k;
        
        // Return true if we can form at least 'm' bouquets
        return (totalBouquets >= m);
    }

    // Main function to find the minimum number of days to make 'm' bouquets of 'k' flowers
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Check if it's possible to make 'm' bouquets, if not return -1
        if (m > bloomDay.size() / k) return -1;

        // Set binary search bounds
        int start = *min_element(bloomDay.begin(), bloomDay.end()); // Earliest bloom day
        int end = *max_element(bloomDay.begin(), bloomDay.end());   // Latest bloom day
        
        int ans = end; // Initialize the answer to the worst case (latest bloom day)

        // Binary search for the minimum number of days
        while (start <= end){
            int mid = start + (end - start) / 2; // Calculate mid point
            
            // Check if it's possible to form 'm' bouquets by day 'mid'
            if (isPossible(bloomDay, m, k, mid)){
                ans = mid;       // Update answer to current 'mid'
                end = mid - 1;   // Try to find a smaller day in the left half
            } else {
                start = mid + 1; // Otherwise, search the right half
            }
        }

        return ans;  // Return the minimum number of days
    }
};