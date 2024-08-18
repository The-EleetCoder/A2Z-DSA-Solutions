/*
https://www.geeksforgeeks.org/problems/insertion-sort/0
*/

// initial approach
void insertionSort(int arr[], int n) {
    // Outer loop to iterate through each element in the array
    for (int i = 0; i < n; i++) {
        int j = i; 

        // Inner loop to move the current element to its correct position
        // The loop continues as long as j is not the first element and the current element is smaller than the previous one
        while (j != 0 && j > 0) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
            j--;
        }
    }
}

// optimised approach
void insertionSort(int arr[], int n) {
    // Loop through the array from the second element
    for (int i = 1; i < n; i++) {
        int j = i;
        
        // While j is greater than 0 and the current element is less than the previous one
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--; 
        }
    }
}

// recursive approach
class Solution
{
    public:
    void insert(int arr[], int i)
    {
        // Base case: stop recursion when i <= 0
        if (i <= 0) {
            return;
        }
        // If current element is smaller than the previous one, swap them
        if (arr[i] < arr[i-1]) {
            swap(arr[i], arr[i-1]);
            // Recursively check and insert the previous elements in the correct position
            insert(arr, i-1);
        }
    }
    
    public:
    // Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for (int i = 1; i < n; i++) {
            // Insert the element at index i in its correct position
            insert(arr, i);
        }
    }
};

/*
Steps for Insertion Sort:

1. Start with the Second Element:
Consider the first element of the array as already sorted.
Begin the sorting process from the second element (index 1).

2. Compare with the Sorted Portion:
Take the current element and compare it with the elements in the sorted portion of the array (elements to the left of the current element).
Move through the sorted portion from right to left.

3. Shift Elements:
If the current element is smaller than the element to its left, shift the larger element to the right.

4. Insert the Current Element:
Continue the shifting process until you find the correct position for the current element within the sorted portion.
Insert the current element at its correct position.

5. Repeat for All Elements:
Repeat the process for each element in the array until the entire array is sorted.
After each iteration, the sorted portion of the array increases by one element.

6. End When All Elements are Sorted:
Continue until all elements have been processed and are in the correct order.
*/

/*
Time Complexity (TC) of Insertion Sort:

Best Case: O(n)
Occurs when the array is already sorted. In this case, the inner loop doesn't need to perform any swaps, and it only compares elements once.

Average Case: O(n^2)
This occurs for a randomly ordered array. On average, each element needs to be compared and shifted multiple times to find its correct position.

Worst Case: O(n^2)
Occurs when the array is sorted in reverse order. In this case, each element needs to be compared and swapped all the way to the beginning of the sorted portion, resulting in the maximum number of operations.

Space Complexity (SC) of Insertion Sort:

Space Complexity: O(1)
Insertion Sort is an in-place sorting algorithm, meaning it doesn't require additional space proportional to the size of the input. It only uses a constant amount of extra space for variables such as i, j, and the temporary variable used in swapping.
*/
