/*
https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
*/

/*
This solution removes the middle node of a singly linked list using the two-pointer technique. If the list has only one node, it returns `NULL` since that node is considered the middle. Otherwise, two pointers, `slow` and `fast`, are initialized. The `fast` pointer moves two steps at a time, and the `slow` pointer moves one step. When the `fast` pointer reaches the end, the `slow` pointer will be at the node just before the middle. The middle node is then deleted by adjusting the `next` pointer of the `slow` pointer to skip the middle node. The time complexity is O(n), with a single traversal of the list.
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // if only 1 node is there
        if (head->next == NULL){
            return NULL;
        }

        // more than 1 node
        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};