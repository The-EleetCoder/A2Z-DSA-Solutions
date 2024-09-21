/*
https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
*/

/*
This solution segregates a linked list containing 0s, 1s, and 2s by grouping nodes of the same value together without altering their relative order. It uses three dummy nodes (`zero`, `one`, and `two`) to create separate lists for nodes with values 0, 1, and 2. During a single traversal of the original list, each node is appended to its respective sublist based on its value. After the traversal, the sublists are linked together, with the 0s list connected to the 1s (if present) and the 1s list connected to the 2s. The combined list is returned, starting from the 0s list. This approach has a time complexity of O(n) as it only requires one pass through the list.
*/

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node* two = new Node(-1);
        
        Node* pointer_to_zero = zero;
        Node* pointer_to_one = one;
        Node* pointer_to_two = two;
        
        Node* temp = head;
        while(temp!=NULL){
            if (temp->data==0){
                pointer_to_zero->next = temp;
                pointer_to_zero = pointer_to_zero->next;
            }
            else if (temp->data==1){
                pointer_to_one->next = temp;
                pointer_to_one = pointer_to_one->next;
            }
            else {
                pointer_to_two->next = temp;
                pointer_to_two = pointer_to_two->next;
            }
            temp = temp->next;
        }
        pointer_to_zero->next = one->next==NULL ? two->next : one->next;
        pointer_to_one->next = two->next;
        pointer_to_two->next = NULL;
        
        return zero->next;
    }
};