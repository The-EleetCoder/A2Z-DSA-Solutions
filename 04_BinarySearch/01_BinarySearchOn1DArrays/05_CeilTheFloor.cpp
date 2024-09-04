/*
https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401
*/

/*
The getFloorAndCeil function finds both the floor and ceiling of a given value x in a sorted vector a. The floor of x is the greatest element in a that is less than or equal to x, and the ceiling is the smallest element in a that is greater than or equal to x. If either does not exist, it returns -1 for that value.
*/

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    int ans_ceil = -1;  // Initialize ceiling to -1 (not found)
    int ans_floor = -1; // Initialize floor to -1 (not found)
    
    int start = 0;           // Initialize the start index
    int end = a.size() - 1;  // Initialize the end index
    
    // Perform binary search within the range [start, end]
    while (start <= end) {
        int mid = start + (end - start) / 2; // Calculate the mid index to avoid overflow
        
        // If the exact value x is found, both floor and ceiling are x
        if (a[mid] == x) {
            ans_floor = a[mid];
            ans_ceil = a[mid];
            break; // Exit the loop since we found the exact match
        }
        // If mid value is greater than x, update the ceiling and search in the left half
        else if (a[mid] > x) {
            ans_ceil = a[mid];
            end = mid - 1;
        }
        // If mid value is less than x, update the floor and search in the right half
        else {
            ans_floor = a[mid];
            start = mid + 1;
        }
    }
    
    // Return a pair of floor and ceiling values
    return {ans_floor, ans_ceil};
}


/*
Key Points:

Binary Search: The function uses binary search to efficiently find both the floor and ceiling of the target value x, operating in O(log n) time complexity.

Floor and Ceil Logic:
Exact Match: If x is found in the array, it is both the floor and the ceiling.
Greater than Mid: If x is greater than the middle element a[mid], then a[mid] could be the floor, and the search continues in the right half.
Less than Mid: If x is less than a[mid], then a[mid] could be the ceiling, and the search continues in the left half.

Edge Cases:
If x is smaller than all elements, the ceiling might be found, but the floor will remain -1.
If x is larger than all elements, the floor might be found, but the ceiling will remain -1.
*/