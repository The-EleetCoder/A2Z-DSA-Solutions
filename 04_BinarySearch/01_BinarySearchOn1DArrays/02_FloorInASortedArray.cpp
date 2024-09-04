/*
https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
*/

/*
The findFloor function searches for the floor of a given value x in a sorted vector v. The floor of x is the greatest element in v that is less than or equal to x. If such an element exists, the function returns its index; otherwise, it returns -1.
*/

// Function to find the floor of x in a sorted vector v
// n: size of the vector
// x: element whose floor is to be found
int findFloor(vector<long long> &v, long long n, long long x) {
    int ans = -1; // Initialize the answer to -1, which indicates no valid floor found
    
    int start = 0; // Initialize the start index
    int end = v.size() - 1; // Initialize the end index

    // Perform binary search within the range [start, end]
    while (start <= end) {
        int mid = start + (end - start) / 2; // Calculate the mid index to avoid overflow

        // If the exact value x is found, return its index
        if (v[mid] == x) {
            ans = mid;
            break; // Floor is the element itself, so exit the loop
        }
        // If mid value is greater than x, narrow the search to the left half
        else if (v[mid] > x) {
            end = mid - 1;
        }
        // If mid value is less than x, it could be the floor
        // Update ans to mid and continue searching in the right half
        else {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans; // Return the index of the floor of x, or -1 if not found
}
