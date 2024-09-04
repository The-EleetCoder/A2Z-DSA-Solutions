/*
https://www.naukri.com/code360/problems/implement-upper-bound_8165383
*/

/*
The upperBound function finds the index of the smallest element in a sorted array arr that is strictly greater than a given value x. If all elements in the array are less than or equal to x, it returns n, which is the size of the array. This function mimics the behavior of the standard upper_bound function in C++.
*/

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0; // Initialize the start index
    int high = n - 1; // Initialize the end index
    int ans = n; // Initialize answer to n, which is the default return value if no upper bound is found

    // Perform binary search within the range [low, high]
    while (low <= high) {
        // Calculate the mid index to avoid overflow
        int mid = low + (high - low) / 2; 
        
        // If the mid element is greater than x, it could be the upper bound
        if (arr[mid] > x) {
            // Update ans to the current mid index
            ans = mid; 
            // Narrow the search to the left half to find a smaller upper bound
            high = mid - 1; 
        }
        // If the mid element is less than or equal to x, continue searching in the right half
        else {
            low = mid + 1;
        }
    }

    // Return the index of the upper bound or n if no such element exists
    return ans; 
}
