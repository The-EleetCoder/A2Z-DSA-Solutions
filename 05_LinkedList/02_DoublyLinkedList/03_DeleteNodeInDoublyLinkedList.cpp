/*
https://geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1
*/

/*
The deleteNode function in C++ deletes a node from a doubly linked list at a specified position x. If the position is 1, indicating the head node, the function updates the head to the next node, sets the prev pointer of the new head to NULL, and detaches the old head. For any other position, the function traverses the list to reach the node just before the one to be deleted. It then updates the next pointer of this node to skip the node being deleted and connects it to the subsequent node, adjusting the prev pointer of the next node if it exists. Finally, the function deletes the node and returns the updated head of the list.
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        Node* temp = head;
        
        if (x==1){
            head = temp->next;
            temp->next=NULL;
            head->prev = NULL;
            return head;
        }
        
        for (int i=1; i<x-1; i++){
            temp = temp->next;
        }
        Node* del = temp->next;
        Node* var = temp->next->next;
        temp->next = var;
        if (var!=NULL)
            var->prev = temp;
        delete del;
        return head;
    }
};