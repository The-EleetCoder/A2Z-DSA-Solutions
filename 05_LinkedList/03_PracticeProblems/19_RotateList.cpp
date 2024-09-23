/*
https://leetcode.com/problems/rotate-list/
*/

/*
This solution aims to **rotate a linked list to the right by `k` positions**. Let’s break down how this is achieved step-by-step:

### Key Observations:
1. **List Rotation Concept**:
   - Rotating the list to the right by `k` positions means taking the last `k` nodes of the list and moving them to the front.
   - For example, given the list `1 -> 2 -> 3 -> 4 -> 5` and `k = 2`, rotating to the right would result in `4 -> 5 -> 1 -> 2 -> 3`.

2. **Edge Cases**:
   - If the list is empty (`head == NULL`), has only one node (`head->next == NULL`), or `k == 0`, the list doesn't need to be rotated, so we simply return the `head`.

### Step-by-Step Approach:

1. **Calculate the Length of the List**:
   - First, a pointer `temp` traverses the list to count the total number of nodes (`count`).
   - During this traversal, `temp` also reaches the last node of the list. This node will be useful later when we need to reconnect the rotated part to the head.
   
2. **Normalize `k`**:
   - Since rotating a list by its length doesn’t change it (i.e., rotating a list of length `n` by `n` or a multiple of `n` results in the same list), we compute `k = k % count`.
   - If `k == 0`, this means the list does not need to be rotated, so we return the original head.

3. **Find the New Tail and New Head**:
   - After normalizing `k`, we need to determine the new tail and the new head of the list after rotation.
   - The new tail will be at position `count - k - 1`, and the new head will be the node just after the new tail (`fast->next`).
   
4. **Rotate the List**:
   - To rotate the list, we do the following:
     - Make the current last node (`temp`, which was identified in the first step) point to the current `head`, effectively creating a circular list.
     - Break the circular list by setting the `next` of the new tail (`fast`) to `NULL`.
     - Set the new head to be `fast->next`.

5. **Return the New Head**:
   - After performing the rotation, we return the new head, which points to the rotated list.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if (temp==NULL || temp->next==NULL || k==0) return temp;
        int count = 1;
        while(temp->next!=NULL){
            count++;
            temp = temp->next;
        }

        k = k % count;
        if (k==0) return head;

        ListNode* fast = head;
        int len = count - k - 1;
        while(len>0 && fast!=NULL){
            fast = fast->next;
            len--;
        }

        if (fast){ 
            ListNode* nextt = fast->next;
            fast->next = NULL;
            temp->next = head;
            head = nextt;
        }

        return head;
    }
};

