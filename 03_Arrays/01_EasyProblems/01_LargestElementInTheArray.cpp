/*
https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279
*/

int largestElement(vector<int> &arr, int n) {
    // Initialize maxElement to 0. This variable will hold the largest element found so far.
    int maxElement = 0;

    // Loop through each element in the array
    for (int i = 0; i < n; i++) {
        // If the current element is greater than the maxElement found so far, update maxElement to the current element's value.
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Return the largest element found in the array
    return maxElement;
}
