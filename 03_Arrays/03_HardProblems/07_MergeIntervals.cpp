/*
https://leetcode.com/problems/merge-intervals/
*/

/*
The goal of this problem is to merge overlapping intervals from a given list of intervals. An interval is represented as a pair of integers, where the first integer represents the start of the interval, and the second integer represents the end of the interval.

Steps:

Sort the Intervals:
First, we sort the intervals based on their starting times. This makes it easier to merge overlapping intervals since any overlapping intervals will be adjacent after sorting.

Initialize Variables:
We initialize start and end with the start and end of the first interval in the sorted list.
We also create an empty result vector ans to store the merged intervals.

Merge Overlapping Intervals:
We iterate through the sorted intervals starting from the second interval.
If the current interval's start is greater than the end of the previous interval, it means there is no overlap. We then push the current start and end as a merged interval into ans and update start and end to the current interval.
If the intervals overlap (i.e., the current interval's start is less than or equal to end), we merge them by extending the end to the maximum of the current end and the current interval's end.

Final Merge:
After the loop, we push the last merged interval into ans.

Return the Result:
The result vector ans contains all the merged intervals.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort the intervals based on the start times
        sort(intervals.begin(), intervals.end());

        // Vector to store the merged intervals
        vector<vector<int>> ans;

        // Initialize the start and end with the first interval
        int start = intervals[0][0];
        int end = intervals[0][1];

        // Traverse through the sorted intervals starting from the second one
        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval's start is greater than the current end, there's no overlap
            if (intervals[i][0] > end) {
                // Push the current merged interval to the result
                ans.push_back({start, end});

                // Update start and end to the current interval
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                // If there is an overlap, merge the intervals by updating the end
                if (intervals[i][1] > end) {
                    end = intervals[i][1];
                }
            }
        }

        // Push the last merged interval into the result
        ans.push_back({start, end});

        // Return the merged intervals
        return ans;
    }
};

/*
Explanation of Key Points
Sorting: The intervals are first sorted by their starting times. This is essential because it simplifies the merging process by ensuring that overlapping intervals are adjacent.

Merging: The merge happens when the start of the current interval is less than or equal to the end of the previous interval. The end is updated to the maximum of the current end and the end of the current interval.

Handling Non-overlapping Intervals: When the current interval does not overlap with the previous one, the current merged interval is pushed to the result, and we start a new interval.

Final Push: After the loop, the last interval must be pushed to the result because it is not done inside the loop.

This approach ensures that the intervals are merged efficiently in O(n log n) time complexity, where n is the number of intervals (due to sorting). The merging process itself runs in O(n) time.
*/