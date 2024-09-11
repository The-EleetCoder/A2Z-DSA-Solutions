/*
https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
*/

/*
Problem Intuition:
The problem aims to find the smallest possible maximum distance between gas stations, given that we can add k new stations. The goal is to minimize the largest distance between two consecutive stations.

We can solve this by:
Using binary search to guess the maximum possible distance (mid).
Checking whether it's possible to add new stations such that the maximum distance between stations is less than or equal to mid.
Repeating the process until we find the smallest maximum distance.
*/

class Solution {
  public:
    // Helper function to check if it's possible to add `k` or fewer stations
    // such that the maximum distance between two consecutive stations is <= mid
    bool isPossible(vector<int> &stations, int k, double mid) {
        int station_count = 0;  // To count how many new stations are needed
        
        // Loop through all the given stations
        for (int i = 1; i < stations.size(); i++) {
            // Calculate the distance between current station and previous station
            double difference = stations[i] - stations[i-1];
            
            // If the distance is greater than `mid`, calculate how many new stations are needed
            if (difference > mid) {
                // We need `difference / mid` stations to make sure no gap is larger than `mid`
                station_count += difference / mid;
            }
        }
        
        // Return true if we can add the required number of stations within the limit `k`
        return station_count <= k;
    }

    // Main function to find the smallest possible maximum distance
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Set up binary search boundaries: minimum and maximum possible distance
        double start = 0;
        int n = stations.size();
        double end = stations[n-1] - stations[0];  // Maximum possible distance

        double ans = 0;  // To store the result (smallest max distance)

        // Perform binary search
        while (start <= end) {
            double mid = start + (end - start) / 2;  // Calculate the mid value (candidate for the max distance)
            
            // Check if it's possible to place `k` stations such that no gap exceeds `mid`
            bool possible = isPossible(stations, k, mid);
            
            if (possible) {
                // If possible, try to find a smaller value (narrow the search)
                ans = mid;  // Update answer to the current mid
                end = mid - 0.000001;  // Try for smaller distances
            } else {
                // If not possible, we need to increase the value of `mid`
                start = mid + 0.000001;  // Increase the search space
            }
        }

        // Return the smallest possible max distance
        return ans;
    }
};


/*
Explanation:
Binary Search on Distance: We perform binary search on the distance between the first and last station, aiming to find the smallest maximum distance possible (mid).

isPossible Function: For each guess (mid), we check if it's possible to place k or fewer stations such that no gap between consecutive stations exceeds mid. This is done by calculating how many additional stations are needed to break large gaps into smaller ones.

Precision Handling: We use 0.000001 to control the precision of the binary search result, ensuring we get a result with a difference smaller than 1e-6.

Time Complexity: The binary search will take about O(log(end-start)), and for each guess, we iterate through the stations to check the feasibility, leading to a time complexity of approximately O(n * log(end-start)).
*/