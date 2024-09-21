/*
https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

/*
### Approach:

1. **Marking List A:**
   - The first traversal through `List A` negates the values of all its nodes. This serves as a temporary marker to help identify nodes from `List A` during the traversal of `List B`.
   
2. **Checking List B for Intersection:**
   - As we traverse `List B`, the code checks if any node in `List B` has a negative value. A negative value indicates that this node belongs to both `List A` and `List B`, thus marking the intersection point. The loop exits as soon as such a node is found.

3. **Restoring List A:**
   - After finding the intersection (or confirming there isn't one), `List A` is traversed again, and all its node values are reverted back to their original state by multiplying them by -1 again, ensuring no permanent changes are made to the values.

4. **Return:**
   - If an intersection node was found during the second traversal, it is returned as the result. If no node in `List B` has a negative value, indicating no intersection, `NULL` is returned.

### Conclusion:

- **Time Complexity:** O(m + n), where `m` is the length of `List A` and `n` is the length of `List B`, because both lists are traversed fully once.
- **Space Complexity:** O(1), as no additional space is used aside from the pointers.

This solution efficiently finds the intersection node by temporarily modifying the node values in `List A`, but crucially, it ensures the values are restored to their original state before returning the result.
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA!=NULL){
            tempA->val = tempA->val * -1;
            tempA = tempA->next;
        }

        while(tempB!=NULL){
            if (tempB->val<0){
                break;
            }
            tempB = tempB->next;
        }

        tempA = headA;
        while(tempA!=NULL){
            tempA->val = tempA->val * -1;
            tempA = tempA->next;
        }

        if (tempB==NULL) return NULL;
        return tempB;
    }
};