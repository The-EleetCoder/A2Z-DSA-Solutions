/*
https://www.naukri.com/code360/problems/subarrays-with-xor-k_6826258
*/

/*
Intuition
The problem is to find the number of subarrays with a given sum b. The approach used here leverages the XOR (exclusive OR) operation, which is particularly useful for solving problems related to subarrays and prefix sums.

Key Concepts:

XOR Operation:
XOR of two numbers gives a number that is a bitwise difference between them.
If you XOR the same number twice, you get zero: x ^ x = 0.
Thus, if xorr1 ^ xorr2 = b, then xorr1 and xorr2 can form a subarray with XOR sum b.

Prefix XOR:
We maintain a prefix XOR (xorr) as we iterate through the array. The prefix XOR up to index i is the XOR of all elements from the start of the array up to index i.
If the XOR of the subarray a[i:j] equals b, then xorr_j ^ xorr_{i-1} = b.

Using a Hash Map:
We use an unordered map (mpp) to store the frequency of different prefix XOR values encountered so far.
For every element, we calculate xorr ^ b and check if this value has been seen before in the map. If it has, it means there is a subarray that can be XORed with the current prefix XOR to give b.

Approach:

1. Initialize xorr to 0 and count to 0.
2. Traverse the array, updating xorr with the XOR of the current element.
3. If xorr itself is equal to b, increment the count (because the subarray starting from the beginning to the current index has XOR equal to b).
4. If xorr ^ b is found in the map, it means there exists a prefix XOR that can form a subarray with XOR b, so add the frequency of xorr ^ b in the map to count.
5. Finally, update the map with the current xorr.
*/

int subarraysWithSumK(vector<int> a, int b) {
    unordered_map<int, int> mpp;
    int xorr = 0;
    int count = 0;

    for (int i = 0; i < a.size(); i++) {
        xorr ^= a[i];

        // If current prefix XOR is equal to b, increment the count
        if (xorr == b) {
            count++;
        }

        // If there exists a prefix XOR that can form a subarray with XOR equal to b
        if (mpp.find(xorr ^ b) != mpp.end()) {
            count += mpp[xorr ^ b];
        }

        // Increment the count of the current prefix XOR in the map
        mpp[xorr]++;
    }

    return count;
}
