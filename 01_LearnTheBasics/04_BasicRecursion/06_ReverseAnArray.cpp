/*
https://www.naukri.com/code360/problems/reverse-the-array_1262298?count=25&page=1&search=&sort_entity=order&sort_order=ASC
*/

// Helper function to recursively reverse the array from index 'start' to 'end'
void func(int start, int end, vector<int> &arr) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    func(start + 1, end - 1, arr);
}

// Main function to reverse the part of the array after index 'm'
void reverseArray(vector<int> &arr, int m) {
    int end = arr.size() - 1;
    func(m + 1, end, arr);
}

