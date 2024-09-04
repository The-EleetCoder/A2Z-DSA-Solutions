/*
https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
*/

/*
The code consists of three functions: firstOccurrence, lastOccurrence, and count. The firstOccurrence function finds the first index at which a target value appears in a sorted array. The lastOccurrence function finds the last index at which the target value appears. The count function calculates how many times the target value appears in the array by using the results of the first two functions.
*/

// Function to find the first occurrence of target in arr
int firstOccurrence(int arr[], int n, int target) {
  int first = -1;
  int start = 0;
  int end = n - 1;

  while (start <= end) {
      int mid = start + (end - start) / 2; 

      if (arr[mid] == target) {
          first = mid;
          end = mid - 1;
      }
      else if (arr[mid] > target) {
          end = mid - 1;
      }
      else {
          start = mid + 1;
      }
  }
  return first;
}

// Function to find the last occurrence of target in arr
int lastOccurrence(int arr[], int n, int target) {
    int last = -1;
    int start = 0;
    int end = n - 1;

    // Perform binary search within the range [start, end]
    while (start <= end) {
        int mid = start + (end - start) / 2; 

        if (arr[mid] == target) {
            last = mid;
            start = mid + 1; 
        }
        else if (arr[mid] > target) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return last;
}

int count(int arr[], int n, int x) {
      int first = firstOccurrence(arr,n, x);
      int last = lastOccurrence(arr,n, x);
      if (first == -1) return 0;
      return last-first+1;
}