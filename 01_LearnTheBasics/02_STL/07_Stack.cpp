/*
A stack is a Last In First Out (LIFO) data structure where elements are added and removed from the top.
*/
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;

    // Pushing elements
    s.push(1);
    s.push(2);
    s.push(3);

    // Accessing the top element
    cout << "Top element: " << s.top() << endl;

    // Popping the top element
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    // Checking if stack is empty
    if (s.empty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
