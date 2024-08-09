/*
A set is an ordered collection of unique elements, automatically sorted.
*/
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s = {5, 1, 4, 2, 3};

    // Adding elements
    s.insert(6);
    s.insert(4); // No effect as 4 is already present

    // Iterating over elements (in sorted order)
    cout << "Set elements: ";
    for (int i : s) {
        cout << i << " ";
    }
    cout << endl;

    // Removing elements
    s.erase(3);
    
    return 0;
}
