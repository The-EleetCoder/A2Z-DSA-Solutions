/*

*/

// optimal approach
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        for (int k=0;k<nums.size();k++){
            if (nums[k]==0){
                i=k;
                break;
            }
        }

        if (i==-1) return ;

        for (int j = i+1;j<nums.size();j++){
            if (nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }
};

/*
Explaination🔥

This C++ solution is designed to move all the zeros in a given vector of integers (nums) to the end of the vector while maintaining the relative order of the non-zero elements. Here's a step-by-step breakdown of how the solution works:

Step-by-Step Breakdown:

1. Initialization:
The solution starts by initializing an integer variable i to -1. This variable i will later be used to track the position of the first zero found in the vector.

2. Find the First Zero:
A for loop iterates over the vector nums to find the first zero. If a zero is found at index k, i is updated to this index, and the loop breaks, stopping further iteration. If no zero is found in the entire vector, i remains -1.

3. Return if No Zero Found:
If i is still -1 after the first loop, it indicates that there are no zeros in the vector, so the function returns immediately as no changes are needed.

4. Move Non-Zero Elements:
Another for loop starts from the element right after the first zero found (j = i + 1).
This loop iterates through the remaining elements in the vector. If a non-zero element is encountered at index j, it swaps this non-zero element with the element at index i (the position of the first zero). After the swap, i is incremented to point to the next zero (or the next element to be swapped).

5. End of the Function:
The loop continues until all non-zero elements have been moved in front of all the zeros.
Once the loop completes, all zeros will have been moved to the end of the vector, with the non-zero elements in their original relative order.


Key Points:

The algorithm operates in-place, meaning no additional space is required other than a few integer variables.
The time complexity is O(n), where n is the size of the vector. This is because each element in the vector is processed at most twice (once to find the first zero and once to perform swaps).

This approach is efficient and simple, effectively moving all zeros to the end of the vector while preserving the order of non-zero elements.
*/ 
