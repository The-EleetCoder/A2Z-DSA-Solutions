/*
https://leetcode.com/problems/sort-list/
*/

/*
This solution implements merge sort on a linked list. The main function `sortList` recursively splits the list into two halves, sorts each half, and then merges them back together.

1. **Base Case:** If the list has 0 or 1 nodes, it is already sorted, so the function returns the head.
2. **Finding the Middle:** The `findMiddle` function uses the two-pointer technique to locate the middle node of the list, which is used to divide the list into two halves.
3. **Recursion:** The list is recursively divided into smaller parts until each sublist has only one node. These sublists are then merged.
4. **Merging:** The `mergeList` function merges two sorted lists (`left` and `right`) into one by comparing the values at each node and appending the smaller one to the result list.

This approach ensures a time complexity of O(n log n) due to the recursive splitting and merging steps.
*/

class Solution {
public:
    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
                temp = temp->next;
            } else {
                temp->next = right;
                right = right->next;
                temp = temp->next;
            }
        }

        if(left!=NULL){
            temp->next = left;
        }
        if (right!=NULL){
            temp->next = right;
        }

        return head->next;
    }

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        // base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* middle = findMiddle(head);

        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);
        return mergeList(left, right);
    }
};