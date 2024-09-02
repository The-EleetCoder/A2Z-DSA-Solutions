/*
https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
*/

vector<int> findTwoElement(vector<int> arr, int n) {
    
    // Step 1: Find A ^ B, where A is the repeated number and B is the missing number.
    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr = xr ^ (i + 1);  // XOR with all numbers from 1 to n
        xr = xr ^ arr[i];   // XOR with all elements in the array
    }
    
    // After this loop, xr = A ^ B, because all numbers except A and B cancel out.

    // Step 2: Find the rightmost differentiating bit between A and B.
    // This bit will help us separate the numbers into two different groups.
    int bitNumber = 0;
    while (true) {
        if ((xr & (1 << bitNumber)) != 0) break;
        bitNumber++;
    }
    
    // Step 3: Divide elements into two groups based on the differentiating bit
    // and XOR them to isolate A and B.
    int group_zero = 0;
    int group_one = 0;
    
    // XOR the array elements based on the differentiating bit.
    for (int i = 0; i < n; i++) {
        if ((arr[i] & (1 << bitNumber)) == 0)
            group_zero ^= arr[i];  // Group 0: Elements where differentiating bit is 0
        else
            group_one ^= arr[i];   // Group 1: Elements where differentiating bit is 1
    }
    
    // XOR the numbers from 1 to n based on the differentiating bit.
    for (int i = 1; i <= n; i++) {
        if ((i & (1 << bitNumber)) == 0)
            group_zero ^= i;  // Group 0: Numbers where differentiating bit is 0
        else
            group_one ^= i;   // Group 1: Numbers where differentiating bit is 1
    }
    
    // After these loops, group_zero and group_one contain either A or B.
    
    // Step 4: Determine which one is the repeated number (A).
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == group_one) count++;
    }
    
    // If group_one is found more than once, it is the repeated number (A).
    // Otherwise, group_zero is the repeated number (A).
    if (count > 1)
        return {group_one, group_zero};  // {A, B}
    else
        return {group_zero, group_one};  // {A, B}
}
