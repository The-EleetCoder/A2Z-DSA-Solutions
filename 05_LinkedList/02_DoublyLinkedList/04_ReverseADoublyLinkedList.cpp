/*
https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
*/

/*
The `reverseDLL` function reverses a doubly linked list by iterating through the list and swapping the `next` and `prev` pointers of each node. It starts from the head of the list, using a pointer `ans` to traverse. For each node, it temporarily stores the current `next` node, swaps the `next` and `prev` pointers, and moves to the previous node (which is now the next node in the reversed list). The loop continues until the end of the list is reached (when `temp == NULL`), and the last node is returned as the new head of the reversed list.
*/

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        DLLNode* ans = head;
        while(true){
            bool flag = false;
            
            DLLNode* temp = ans->next;
            if (temp==NULL) flag=true;
            
            ans->next = ans->prev;
            ans->prev = temp;
            if(flag) break;
            ans = ans->prev;
        }
        return ans;
    }
};