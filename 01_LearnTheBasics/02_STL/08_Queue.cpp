/*
A queue is a First In First Out (FIFO) data structure where elements are added at the back and removed from the front.
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;

    // Enqueue elements
    q.push(1);
    q.push(2);
    q.push(3);

    // Accessing the front and back elements
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // Dequeue the front element
    q.pop();
    cout << "Front element after pop: " << q.front() << endl;

    // Checking if queue is empty
    if (q.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
