/*
https://leetcode.com/problems/linked-list-cycle-ii/
*/

/*
This solution builds on Floyd's Cycle Detection Algorithm to not only detect a cycle in a linked list but also find the node where the cycle begins. Two pointers, `slow` and `fast`, are used, both starting at the head of the list. The `slow` pointer moves one step at a time, while the `fast` pointer moves two steps at a time. If the two pointers meet, it confirms the presence of a cycle. At this point, the `slow` pointer is reset to the head of the list, and both pointers are moved one step at a time. The next time the `slow` and `fast` pointers meet, they will meet at the start of the cycle. The function then returns the node where the cycle begins. If no cycle is detected, the function returns `NULL`.
*/

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};