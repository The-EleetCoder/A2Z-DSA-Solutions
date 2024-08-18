/*
https://www.geeksforgeeks.org/problems/bubble-sort/1
*/

/*
Bubble Sort Algorithm Steps:

1. Compare Adjacent Elements: Start with the first two elements in the array. Compare them.

2. Swap If Necessary: If the first element is greater than the second, swap them.

3. Move to the Next Pair: Move to the next pair of adjacent elements and repeat the comparison and swap process.

4. Largest Element "Bubbles" to the End: After each pass through the array, the largest element in the unsorted portion "bubbles up" to its correct position at the end.

5.Repeat for Remaining Unsorted Portion: Reduce the unsorted portion of the array by one and repeat the process until the entire array is sorted.
*/

// Initial approach
class Solution {
public:

    void bubbleSort(int arr[], int n) {
        // Outer loop runs n times to ensure complete sorting
        for (int k = 0; k < n; k++) {
            int j = 0;
            // Inner loop for comparing adjacent elements
            for (int i = 1; i < n - k; i++) {
                // Compare current element with the previous one
                if (arr[j] > arr[i]) {
                    swap(arr[i], arr[j]);
                }
                j++;
            }
        }
    }
};

//optimised approach
class Solution {
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        // Outer loop for each pass
        for (int k = 0; k < n - 1; k++) {
            bool swapped = false;  // Track if a swap was made during this pass

            // Inner loop for comparing adjacent elements
            for (int i = 0; i < n - k - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    // Swap if the current element is greater than the next
                    swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }

            // If no swaps were made, the array is already sorted
            if (!swapped) break;
        }
    }
};

// recursive way 
void bubble_sort(int arr[], int n) {
    // Base Case: range == 1.
    if (n == 1) return;

    int didSwap = 0;
    for (int j = 0; j < n - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          swap(arr[j],arr[j+1]);
          didSwap = 1;
        }
    }

    if (didSwap==0) return;

    //Range reduced after recursion:
    bubble_sort(arr, n - 1);
}
