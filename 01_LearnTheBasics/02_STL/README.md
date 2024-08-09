# Standard Template Library
STL is one of the unique abilities of C++ which makes it stand out from every other programming language. STL stands for standard template library which contains a lot of pre-defined templates in terms of containers and classes which makes it very easy for developers or programmers to implement different data structures easily without having to write complete code and worry about space-time complexities.
STL has 4 components:

|Algorithms|Containers|Functors|Iterators|
|-|-|-|-|

In this tutorial we will stick to some of the most popular STL containers and algorithms, and its useful functions which is used by programmers very frequently in day to day programming.

1. __Containers__: The STL provides a range of containers, such as vector, list, map, set, and stack, which can be used to store and manipulate data.  
2. __Algorithms__: The STL provides a range of algorithms, such as sort, find, and binary_search, which can be used to manipulate data stored in containers.  
3. __Iterators__: Iterators are objects that provide a way to traverse the elements of a container. The STL provides a range of iterators, such as forward_iterator, bidirectional_iterator, and random_access_iterator, that can be used with different types of containers.

## Containers
### 1. Vector
A vector is a dynamic array that can change its size during runtime.
```c++
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
```

### 2. List
A list is a doubly linked list that allows fast insertion and deletion.
```c++
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
```
### 3. Map
A map is an associative container that stores elements in key-value pairs, sorted by keys.
```c++
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
```
### 4. Unordered Map
An unordered_map is an associative container that stores elements in key-value pairs, but without any specific order. It uses a hash table for fast access.
```c++
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
```
