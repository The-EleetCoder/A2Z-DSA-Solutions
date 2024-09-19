/*
https://leetcode.com/problems/odd-even-linked-list/
*/

/*
The given solution rearranges a linked list by grouping all nodes at odd indices followed by nodes at even indices. The approach begins by handling edge cases where the list has fewer than three nodes. It then initializes two pointers, one for the odd-indexed nodes (`pointer1`) and one for the even-indexed nodes (`pointer2`). The algorithm iterates through the list, adjusting the `next` pointers such that odd-indexed nodes are linked together and even-indexed nodes are linked together. After traversal, it connects the end of the odd-indexed list to the head of the even-indexed list, ensuring the desired grouping. The time complexity of the solution is O(n).
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // if list has 0, 1, 2 nodes
        if (head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }

        ListNode* head1 = head;
        ListNode* head2 = head->next;

        ListNode* pointer1 = head1;
        ListNode* pointer2 = head2;

        while((pointer1!=NULL && pointer1->next!=NULL) && (pointer2!=NULL && pointer2->next!=NULL)){
            pointer1->next = pointer1->next->next;
            pointer2->next = pointer2->next->next;
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }
        pointer1->next = head2;
        return head;
    }
};