/*
https://leetcode.com/problems/delete-node-in-a-linked-list/
*/

/*
This C++ function deleteNode efficiently deletes a given node from a singly linked list, but with the constraint that you're only given access to that node (not the head of the list). The function works by copying the value and the next pointer of the next node (temp) into the current node, effectively making the current node a duplicate of the next node. It then "skips" over the next node by updating the next pointer to bypass it.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
    }
};