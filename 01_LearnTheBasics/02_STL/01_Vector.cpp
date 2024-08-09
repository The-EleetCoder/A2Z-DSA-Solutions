/*
A vector is a dynamic array that can change its size during runtime.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    // Adding elements
    v.push_back(6);

    // Accessing elements
    cout << "Element at index 2: " << v[2] << endl;

    // Iterating over elements
    cout << "Vector elements: ";
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    // Removing elements
    v.pop_back();

    return 0;
}
