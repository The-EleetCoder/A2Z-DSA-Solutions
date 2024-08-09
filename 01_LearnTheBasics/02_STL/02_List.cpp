/*
A list is a doubly linked list that allows fast insertion and deletion.
*/
#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l = {1, 2, 3, 4, 5};

    // Adding elements
    l.push_back(6);
    l.push_front(0);

    // Iterating over elements
    cout << "List elements: ";
    for (int i : l) {
        cout << i << " ";
    }
    cout << endl;

    // Removing elements
    l.pop_back();
    l.pop_front();

    return 0;
}