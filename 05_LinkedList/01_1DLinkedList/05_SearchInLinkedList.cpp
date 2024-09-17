/*
https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1
*/

/*
The `searchKey` function in C++ is designed to search for a specific key in a singly linked list. The function takes the number of nodes `n`, a pointer to the head of the list, and the key to be searched. It starts by initializing a pointer `temp` to the head of the list. The function then traverses the list, checking each node's `data` to see if it matches the key. If the key is found, the function immediately returns `true`. If the entire list is traversed and the key is not found, the function returns `false`. This efficiently checks whether the key exists in the list.
*/

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        Node* temp = head;
        
        while(temp!=NULL){
            if (temp->data==key) return true;
            temp = temp->next;
        }
        return false;
    }
};