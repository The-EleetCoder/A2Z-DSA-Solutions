/*
https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0
*/

/*
The `getCount` function in C++ is designed to count the number of nodes in a singly linked list. It starts by initializing a `count` variable to 0 and a pointer `temp` to the head of the list. The function then enters a loop that traverses the list by moving the `temp` pointer from one node to the next until it reaches the end (i.e., `temp == NULL`). For each node visited, the count is incremented by 1. Once the traversal is complete, the function returns the total count of nodes, effectively calculating the size of the linked list.
*/

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        int count = 0;
        Node* temp = head;
        
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
};