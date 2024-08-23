/*
https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
*/

// Initial approach - using set
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        set<int> s;
        int i = 0, j = 0;

        // Traverse both arrays
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                s.insert(arr1[i]);
                i++;
            } else {
                s.insert(arr2[j]);
                j++;
            }
        }

        // Store remaining elements of the first array
        while (i < n) {
            s.insert(arr1[i++]);
        }

        // Store remaining elements of the second array
        while (j < m) {
            s.insert(arr2[j++]);
        }

        // Convert set to vector and return
        vector <int> ans;
        for( int i : s){
            ans.push_back(i);
        }
        
        return ans;
    }
};


// Optimal Approach - Using 2 pointer
class Solution{
    public:
    // Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> unionArr;
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (arr1[i] == arr2[j]) {
                if (unionArr.empty() || unionArr.back() != arr1[i]) {
                    unionArr.push_back(arr1[i]);
                }
                i++;
                j++;
            } else if (arr1[i] < arr2[j]) {
                if (unionArr.empty() || unionArr.back() != arr1[i]) {
                    unionArr.push_back(arr1[i]);
                }
                i++;
            } else {
                if (unionArr.empty() || unionArr.back() != arr2[j]) {
                    unionArr.push_back(arr2[j]);
                }
                j++;
            }
        }

        // Add remaining elements of arr1
        while (i < n) {
            if (unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }

        // Add remaining elements of arr2
        while (j < m) {
            if (unionArr.empty() || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
        return unionArr;
    }
};