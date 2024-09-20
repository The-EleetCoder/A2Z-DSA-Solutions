/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

/*
The solution removes the nth node from the end of a singly linked list. It first calculates the length of the list by iterating through the list once. Then, it checks if the node to be deleted is the head (i.e., when the length minus `n` equals 0) and updates the head pointer accordingly. Otherwise, it iterates through the list again to reach the node just before the one to be deleted. The next pointer of this node is adjusted to skip the nth node from the end. The time complexity of this approach is O(n) due to two passes through the list.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // length of list
        ListNode* temp = head;
        int count = 1;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }

        // if head is to be deleted
        if(count-n==0){
            head = head->next;
            return head;
        }

        temp = head;
        for (int i=1; i<count-n; i++){
            temp = temp->next;
        }

        if (temp->next!=NULL){
            temp->next = temp->next->next;
            return head;
        } else {
            return NULL;
        }
        
    }
};

// optimised solution ( using two pointer (fast slow))
/*
The solution efficiently removes the nth node from the end of a singly linked list using a two-pointer technique. It first moves the `fast` pointer `n` steps ahead of the `slow` pointer. If `fast` reaches the end, the node to be deleted is the head, so the head pointer is updated to the next node. Otherwise, both `fast` and `slow` pointers move together until `fast` reaches the last node. At this point, the `slow` pointer is just before the node to be removed, and the `next` pointer of `slow` is updated to skip the nth node from the end. The time complexity of this approach is O(n), requiring only one pass through the list.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for (int i=0; i<n; i++){
            fast = fast->next;
        }

        if (fast==NULL){
            head = head->next;
            return head;
        }

        ListNode* slow = head;
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};