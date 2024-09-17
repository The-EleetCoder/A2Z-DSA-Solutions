/*
https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1
*/

/*
The given C++ code defines a Node class for constructing a singly linked list. Each node in the list holds an integer data and a pointer next to the subsequent node. The class includes two constructors: a default constructor that initializes the data to 0 and the next pointer to NULL, and a parameterized constructor that initializes the data with a specified value. The Solution class includes a method constructLL that takes a vector of integers and builds a linked list by sequentially creating nodes for each element in the vector. It returns the head of the constructed linked list.
*/

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node* head = new Node(arr[0]);
        Node* mover = head;
        
        for (int i=1;i<arr.size(); i++){
            Node* temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
};