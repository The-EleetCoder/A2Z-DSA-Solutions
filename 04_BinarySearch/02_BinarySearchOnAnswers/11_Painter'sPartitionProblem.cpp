/*
https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557
*/

/*
The problem you're solving is based on the Painter's Partition Problem. The goal is to minimize the maximum time a painter takes to paint k boards, where each painter can paint a contiguous segment of the boards. You need to find the minimal possible maximum time for any painter to paint the boards, and you can solve this using binary search combined with a greedy check.

Key Intuition:
Objective:
Given an array boards representing the length of each board and k painters, you need to partition the boards into k contiguous sections such that the maximum sum of the lengths in any section (which represents the total time a painter takes) is minimized.

Binary Search on Maximum Time:
The idea is to perform binary search on the maximum time any painter can take. The minimum time for any painter is the length of the largest board (start), since no painter can paint a board smaller than the longest board. The maximum time is the total sum of the lengths of all the boards (end), which would occur if only one painter paints all the boards.

Greedy Check (isPossible function):
For each candidate mid (which represents the maximum time a painter can take), the function isPossible checks if it's feasible to partition the boards such that no painter paints for more than mid units of time.
*/


// Helper function to check if it's possible to partition the boards into at most `k` painters
// such that no painter paints for more than `mid` units of time.
int isPossible(vector<int> &boards, int k, int mid) {
    int current_length = 0;     // Current sum of board lengths assigned to a painter
    int painter_count = 1;      // Start with the first painter

    // Traverse through each board
    for (int i = 0; i < boards.size(); i++) {
        // If adding the current board exceeds `mid`, assign this board to the next painter
        if (current_length + boards[i] > mid) {
            current_length = boards[i];  // Start a new segment for the next painter
            painter_count++;             // Increment the painter count
            
            // If the number of painters exceeds `k`, it's not possible with this `mid`
            if (painter_count > k)
                return false;
        } else {
            // Otherwise, add the current board to the current painter's work
            current_length += boards[i];
        }
    }

    // If the number of painters required is less than or equal to `k`, return true
    return (painter_count <= k);
}

// Function to find the minimal possible maximum distance (time) a painter will take
int findLargestMinDistance(vector<int> &boards, int k) {
    // The minimum possible time is the largest single board (since no painter can paint less)
    int start = *max_element(boards.begin(), boards.end());

    // The maximum possible time is the sum of all the board lengths (if one painter paints all)
    int end = accumulate(boards.begin(), boards.end(), 0);
    
    int ans = -1;  // This will store the result

    // Binary search to find the minimum possible maximum time
    while (start <= end) {
        int mid = start + (end - start) / 2;  // Calculate mid as a candidate for the maximum time

        // Check if it's possible to partition the boards with this `mid` value
        bool possible = isPossible(boards, k, mid);

        if (possible) {
            // If it's possible, store the answer and try for a smaller maximum time
            ans = mid;
            end = mid - 1;
        } else {
            // If it's not possible, increase the lower bound to try larger values of `mid`
            start = mid + 1;
        }
    }

    // Return the minimal possible maximum time (distance)
    return ans;
}


/*
Intuition Behind the Code:

Binary Search Setup:
Lower bound (start): The largest board in the array. No painter can paint a board that is larger than the largest board in less time than that.
Upper bound (end): The sum of all the board lengths. If one painter were to paint all the boards, this would be the total time required.
Target: We need to find the minimum possible value of mid such that it is possible to partition the boards among k painters with a maximum workload of mid units of time.

Greedy Check (isPossible function):
For a given mid (maximum allowable time per painter), we go through the list of boards and try to assign them to painters. If the current painter cannot handle the next board within the mid time limit, we assign a new painter.
We count the number of painters needed. If the number of painters exceeds k, it's not possible to partition the boards with this mid.

Binary Search Logic:
If it is possible to partition the boards with a maximum time of mid, then we try to lower the time further (because we want to minimize the maximum time). So, we move to the left half of the search space (end = mid - 1).
If it's not possible, we increase the minimum allowable time (start = mid + 1) to see if a higher time will make it feasible.

Optimal Answer:
The result is stored in ans, which is the smallest value of mid for which it is possible to partition the boards among k painters.
*/