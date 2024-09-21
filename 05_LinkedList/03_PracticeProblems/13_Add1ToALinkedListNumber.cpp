/*
https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
*/

/*
This solution adds 1 to a number represented by a singly linked list, where each node contains a single digit, and the digits are stored in reverse order (least significant digit first). The key steps involve reversing the list, adding 1, and then reversing the list again.

### Approach:

1. **Reverse the List:**
   - First, the `reverseList` function is used to reverse the linked list. This makes it easier to add 1 to the number, starting from the least significant digit.
   
2. **Add One:**
   - After reversing, the algorithm traverses the reversed list and adds 1 to the first node (the least significant digit). If the node's value becomes 10 (i.e., the digit was 9 before addition), the value is set to 0, and a carry of 1 is propagated to the next node.
   - This process continues until either the carry is handled, or the entire list is traversed. If the last node still carries a 1 after traversal (e.g., the number was 999), a new node with the value 1 is appended.

3. **Reverse the List Again:**
   - Finally, the list is reversed back to its original order, with the updated value reflecting the addition of 1.

### Explanation:

- **Reversing:** The list is reversed twice — once before adding and once after adding — so the original order is maintained.
- **Carry Handling:** If a digit turns into 10 during the addition, it is reset to 0, and a carry is propagated to the next node. If the entire list has been traversed and there's still a carry (e.g., adding 1 to `999`), a new node with the value 1 is added to handle the overflow.
- **Time Complexity:** O(n), where `n` is the length of the list, as we traverse the list three times (once for reversing, once for adding, and once for the final reversal).
- **Space Complexity:** O(1), as the solution only uses a few additional pointers for traversal and carries.

This method efficiently handles the task of adding 1 to a number represented by a linked list without altering the number's original structure.
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextt = head;

        while(curr!=NULL){
            nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
        }
        return prev;
    }
    
    Node* addOne(Node* head) {
        Node* reverseHead = reverseList(head);
        Node* temp = reverseHead;
        int carry = 1;
        
        while(temp!=NULL){
            if (temp->data==9 && carry==1){
                temp->data = 0;
            }
            else {
                temp->data = temp->data + carry;
                carry = 0;
                break;
            }
            
            if (temp->next==NULL) break;
            temp = temp->next;
        }
        
        if (carry==1){
            Node* lastNode = new Node(1);
            temp->next = lastNode;
            temp = temp->next;
        }
        return reverseList(reverseHead);
    }
};