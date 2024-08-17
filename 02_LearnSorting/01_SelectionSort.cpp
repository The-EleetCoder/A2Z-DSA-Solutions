/*
https://www.geeksforgeeks.org/problems/selection-sort/1
*/

/*
Steps for Selection Sort:

1. Initialize:
Start with the first element of the array (let's call its index i) and assume it is the minimum element.

2. Find the Minimum Element:
Traverse the unsorted portion of the array starting from index i + 1 to the end of the array.
Compare each element in this portion with the current minimum.
If you find an element smaller than the current minimum, update the minimum element's index.

3. Swap:
After completing the inner loop, the smallest element in the unsorted portion is identified.
Swap this smallest element with the element at index i.

4. Move to the Next Element:
Increment i to move to the next element in the array.
The portion of the array before index i is now considered sorted.

5. Repeat:
Repeat the process from step 2 until the entire array is sorted.
The outer loop continues until i reaches the second-to-last element in the array, as the last element will already be sorted by then.


Time Complexity:
Best, Average, and Worst Case: O(n²) where n is the number of elements in the array.
Selection Sort has the same time complexity in all cases because it always performs the same number of comparisons regardless of the initial order of elements.

Space Complexity:
O(1): The algorithm is in-place and does not require additional memory for another array.
This method is simple but inefficient for large datasets. It is best used for small or nearly sorted arrays.
*/

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        // Find the minimum element in the unsorted portion of the array
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted portion
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}