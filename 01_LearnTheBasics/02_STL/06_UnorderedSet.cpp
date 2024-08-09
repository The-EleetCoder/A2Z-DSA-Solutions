/*
An unordered_set is a collection of unique elements, but with no particular order. It's implemented using a hash table.
*/
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> us = {5, 1, 4, 2, 3};

    // Adding elements
    us.insert(6);
    us.insert(4); // No effect as 4 is already present

    // Iterating over elements (order is not guaranteed)
    cout << "Unordered set elements: ";
    for (int i : us) {
        cout << i << " ";
    }
    cout << endl;

    // Removing elements
    us.erase(3);

    return 0;
}
