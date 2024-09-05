/*
https://www.geeksforgeeks.org/problems/rotation4723/1
*/

int findKRotation(vector<int> &arr) {
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    // Perform a binary search to find the minimum element index
    while (start < end) {
        int mid = start + (end - start) / 2;

        // If the array is sorted from start to end, return the start index
        if (arr[mid] >= arr[start] && arr[mid] <= arr[end]) {
            return start;
        }
        // If the left half is sorted, search in the right half
        else if (arr[mid] >= arr[start]) {
            start = mid + 1;
        }
        // If the right half is unsorted, search in the left half
        else {
            end = mid;
        }
    }
    // Return the minimum element after binary search
    return end;
}
