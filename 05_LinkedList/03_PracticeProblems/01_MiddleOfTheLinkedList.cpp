/*
https://leetcode.com/problems/middle-of-the-linked-list/
*/

/*
The `middleNode` function efficiently finds the middle node of a singly linked list using the two-pointer technique. It initializes two pointers, `fast` and `slow`, both starting at the head of the list. The `fast` pointer moves two nodes at a time, while the `slow` pointer moves one node at a time. When the `fast` pointer reaches the end of the list (either `NULL` or the node just before `NULL`), the `slow` pointer will be at the middle node. The function then returns the `slow` pointer, which points to the middle node of the list. This approach operates in O(n) time with O(1) space.
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){
                fast = fast->next->next;
                slow = slow->next;
        }
        return slow;
    }
};