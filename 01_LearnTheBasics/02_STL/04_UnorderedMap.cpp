/*
An unordered_map is an associative container that stores elements in key-value pairs, but without any specific order. It uses a hash table for fast access.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> um;

    // Inserting elements
    um["apple"] = 50;
    um["banana"] = 30;
    um["cherry"] = 20;

    // Accessing elements
    cout << "Price of apple: " << um["apple"] << endl;

    // Iterating over elements (order is not guaranteed)
    cout << "Unordered map elements: " << endl;
    for (const auto& pair : um) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
