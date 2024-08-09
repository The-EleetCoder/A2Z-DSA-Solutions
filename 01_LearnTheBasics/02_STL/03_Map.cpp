/*
A map is an associative container that stores elements as key-value pairs.
*/
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> m;
    
    // Inserting elements
    m["apple"] = 50;
    m["banana"] = 30;
    m["cherry"] = 20;

    // Accessing elements
    cout << "Price of apple: " << m["apple"] << endl;

    // Iterating over elements (in sorted order by keys)
    cout << "Map elements: " << endl;
    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
