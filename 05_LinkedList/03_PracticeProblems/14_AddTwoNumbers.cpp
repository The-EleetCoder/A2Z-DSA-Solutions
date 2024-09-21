/*
https://leetcode.com/problems/add-two-numbers/
*/

/*
This solution adds two numbers represented as singly linked lists, where each node contains a single digit, and the digits are stored in reverse order (i.e., the least significant digit comes first). The solution adds corresponding digits from the two lists, manages the carry from each addition, and constructs a new linked list representing the sum.

### Approach:

1. **Initialize Pointers and Dummy Node:**
   - Two pointers `temp1` and `temp2` are initialized to traverse `l1` and `l2`, respectively. 
   - A `dummyNode` is created to help in constructing the result list, and a `carry` variable is initialized to handle overflow during addition.

2. **Add Corresponding Nodes:**
   - While both lists have nodes left, corresponding nodes are added along with any carry from the previous sum. The new digit is stored in a new node, and the carry is updated accordingly.
   
3. **Handle Remaining Nodes:**
   - If one list is longer than the other, the remaining nodes of the longer list are added to the result. These nodes are added along with the carry.
   
4. **Add Final Carry:**
   - If there is a leftover carry after adding all the nodes, a new node is created for the carry and appended to the result list.

5. **Return the Result:**
   - The result linked list starts from `dummyNode->next`, since `dummyNode` is a placeholder.

### Explanation:

- **Handling Carries:** After adding two digits, if their sum is greater than or equal to 10, the carry is stored and applied to the next addition.
- **Edge Case:** If both input lists are empty or one of the lists is significantly shorter, the solution handles those cases seamlessly with the while loops and carry management.
- **Time Complexity:** O(max(m, n)), where `m` and `n` are the lengths of `l1` and `l2`. Each list is traversed once.
- **Space Complexity:** O(max(m, n)), as the space for the result list will be proportional to the longer input list.

This solution efficiently adds two numbers represented by linked lists, taking into account different lengths and carries from the sum of individual digits.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;

        while(temp1!=NULL && temp2!=NULL){
            int sum = carry + temp1->val + temp2->val;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(digit);
            curr->next = temp;
            curr = curr->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1!=NULL){
            int sum = carry + temp1->val;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(digit);
            curr->next = temp;
            curr = curr->next;
            temp1 = temp1->next;
        }

        while(temp2!=NULL){
            int sum = carry + temp2->val;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(digit);
            curr->next = temp;
            curr = curr->next;
            temp2 = temp2->next;
        }

        if(carry!=0){
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
            curr = curr->next;
        }
        return dummyNode->next;

    }
};