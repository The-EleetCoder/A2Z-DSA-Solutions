/*
https://leetcode.com/problems/linked-list-cycle/
*/

/*
The given solution uses the Floyd's Cycle Detection Algorithm (also known as the Tortoise and Hare algorithm) to determine whether a linked list has a cycle. It employs two pointers: `slow` and `fast`. Both start at the head of the list, with the `slow` pointer moving one step at a time and the `fast` pointer moving two steps at a time. The loop continues until either the `fast` pointer reaches the end (indicating no cycle) or the `slow` and `fast` pointers meet (indicating a cycle). If the two pointers meet, it confirms the presence of a cycle, and the function returns `true`. If the loop exits without the pointers meeting, the function returns `false`, meaning no cycle was detected.
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast) return true; 
        }
        return false;
    }
};