/*
https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1
*/

/*
The given C++ function constructDLL constructs a doubly linked list (DLL) from a vector of integers. The function takes a reference to a vector arr as input and returns the head of the newly created DLL. It first creates the head node using the first element of the array and then iterates through the remaining elements, creating new nodes and linking them to both the previous and next nodes. Specifically, for each new node, it sets the next pointer of the previous node and the prev pointer of the current node, ensuring that each node is properly connected in both directions. Finally, the function returns the head of the constructed doubly linked list.
*/

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        Node* head = new Node(arr[0]);
        Node* temp = head;
        
        for (int i=1;i<arr.size();i++){
            Node* curr = new Node(arr[i]);
            temp->next = curr;
            curr->prev = temp;
            temp = temp->next;
        }
        return head;
    }
};