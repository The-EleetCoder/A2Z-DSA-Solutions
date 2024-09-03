/*
https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
*/

// brute force - gives TLE
long long int inversionCount(long long arr[], int n) {
    long long int count = 0;
    for (long long int i=0;i<n;i++){
        for (long long int j=i+1;j<n;j++){
            if (arr[i]>arr[j]) count++;
        }
    }
    return count;
}


// optimal approach - Merge sort implementation
long long int merge(long long arr[], int l, int m, int r) {
    // Temporary vector to store merged subarrays
    vector<long long> temp(r - l + 1);
    
    int k = 0;      // Index for temp vector
    int i = l;      // Start index for left subarray
    int j = m + 1;  // Start index for right subarray
    long long int count = 0;  // Count of inversions
    
    // Merge the two subarrays while counting inversions
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];  // No inversion, take element from left subarray
        } else {
            temp[k++] = arr[j++];  // Inversion found, take element from right subarray
            count += m - i + 1;    // Count inversions
        }
    }
    
    // Copy any remaining elements from the left subarray
    while (i <= m) {
        temp[k++] = arr[i++];
    }
    
    // Copy any remaining elements from the right subarray
    while (j <= r) {
        temp[k++] = arr[j++];
    }
    
    // Copy merged elements back into the original array
    for (int i = 0; i < temp.size(); i++) {
        arr[l + i] = temp[i];
    }
    return count;
}

long long int mergeSort(long long arr[], int l, int r) {
    long long int count = 0;
    // Base case: single element is already sorted
    if (l < r) {
        int mid = l + (r - l) / 2;
        
        // Recursively sort and count inversions in left half
        count += mergeSort(arr, l, mid);
        
        // Recursively sort and count inversions in right half
        count += mergeSort(arr, mid + 1, r);
        
        // Merge two halves and count cross-inversions
        count += merge(arr, l, mid, r);
    }
    return count;
}

long long int inversionCount(long long arr[], int n) {
    // Initialize merge sort and return total inversion count
    return mergeSort(arr, 0, n - 1);
}
