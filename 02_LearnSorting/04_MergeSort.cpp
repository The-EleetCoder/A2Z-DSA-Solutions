/*
https://www.geeksforgeeks.org/problems/merge-sort/1
*/

class Solution
{
public:
    // Function to merge two sorted subarrays into one sorted array
    void merge(int arr[], int l, int m, int r)
    {
        // Create a temporary vector to hold the merged result
        vector<int> temp(r - l + 1);
        
        int k = 0;  // Index for the temporary vector
        int i = l;  // Starting index for the left subarray
        int j = m + 1;  // Starting index for the right subarray
        
        // Merge elements from both subarrays into temp[]
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];  // Add element from left subarray and move pointer
            } else {
                temp[k++] = arr[j++];  // Add element from right subarray and move pointer
            }
        }
        
        // If there are remaining elements in the left subarray, add them to temp[]
        while (i <= m) {
            temp[k++] = arr[i++];
        }
        
        // If there are remaining elements in the right subarray, add them to temp[]
        while (j <= r) {
            temp[k++] = arr[j++];
        }
        
        // Copy the merged elements from temp[] back into the original array
        for (int i = 0; i < temp.size(); i++) {
            arr[l + i] = temp[i];
        }
    }
    
public:
    // Function to implement merge sort on the array
    void mergeSort(int arr[], int l, int r) {
        
        // Base case: If the array has one or no elements, it is already sorted
        if (l == r) return;
        // Calculate the middle index to divide the array into two halves
        int mid = l + (r - l) / 2;
        // Recursively sort the left half of the array
        mergeSort(arr, l, mid);
        // Recursively sort the right half of the array
        mergeSort(arr, mid + 1, r);
        // Merge the two sorted halves into a single sorted array
        merge(arr, l, mid, r);
    }
};

/*
Time complexity: O(nlogn) 
Reason: At each step, we divide the whole array, for that logn and we assume n steps are taken to get sorted array, so overall time complexity will be nlogn

Space complexity: O(n)  
Reason: We are using a temporary array to store elements in sorted order.
*/