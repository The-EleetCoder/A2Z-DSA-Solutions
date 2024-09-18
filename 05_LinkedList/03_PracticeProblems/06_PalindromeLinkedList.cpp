/*
https://leetcode.com/problems/palindrome-linked-list/
*/

/*
This solution checks if a singly linked list is a palindrome. It does so in three main steps:

1. Finding the middle of the linked list: The `middleNode` function uses two pointers, `fast` and `slow`, where the `fast` pointer moves two steps at a time and the `slow` pointer moves one step. When the `fast` pointer reaches the end, the `slow` pointer will be at the middle node of the list.

2. Reversing the second half of the list: The `reverseList` function reverses the portion of the list starting from the middle. This is done by iterating through the list and reversing the direction of the pointers.

3. Comparing both halves of the list: After reversing the second half, the code compares the values of the nodes from the first half (`head1`) and the reversed second half (`head2`). If all corresponding nodes match, the list is a palindrome; otherwise, it's not.

4. Restoring the original list: Before returning, the second half is reversed back to its original order to maintain the linked list's structure.

If all comparisons are equal, the function returns `true`, indicating the list is a palindrome. Otherwise, it returns `false`.
*/

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

    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){
                fast = fast->next->next;
                slow = slow->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        // find the middle
        ListNode* middle = middleNode(head);

        // reverse the second half
        ListNode* newHead = reverseList(middle);

        // comparing both the halfs
        ListNode* head1 = head;
        ListNode* head2 = newHead;

        while(head1!=NULL && head2!=NULL){
            if (head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }

        // reverse the second half again to maintain the LL
        reverseList(newHead);

        return true;
    }
};