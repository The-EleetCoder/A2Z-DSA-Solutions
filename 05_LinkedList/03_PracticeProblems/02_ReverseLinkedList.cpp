/*
https://leetcode.com/problems/reverse-linked-list/
*/

/*
The `reverseList` function reverses a singly linked list using an iterative approach. It initializes three pointers: `prev` (set to `NULL`), `curr` (starting at the head of the list), and `nextt` (also initialized to the head). During each iteration, the function stores the next node, reverses the link by making the current node point to the previous one, then updates `prev` to the current node and moves `curr` to the next node. This process continues until all nodes are reversed. The function then returns `prev`, which now points to the new head of the reversed list. The approach operates in O(n) time with O(1) space.
*/

// iterative way
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextt = head;

        while(curr!=NULL){
            nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
        }
        return prev;
    }
};

// recursive way
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // base case
        if (head == NULL || head->next==NULL)
            return head;

        ListNode* newHead = reverseList(head->next);

        ListNode* temp = head->next;
        head->next = NULL;
        temp->next = head;

        return newHead;
    }
};