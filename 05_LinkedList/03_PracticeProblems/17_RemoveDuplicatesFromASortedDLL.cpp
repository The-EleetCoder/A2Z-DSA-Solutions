/*
https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
*/

/*
### Explanation of the Approach:

The function `removeDuplicates` removes duplicate nodes from a **sorted doubly linked list**. In a sorted list, duplicate nodes will always be adjacent to each other, which simplifies the task of detecting and removing them. Here’s a breakdown of how the approach works:

### Approach:

1. **Base Case (Edge Case):**
   - If the list is empty (`head == NULL`) or has only one node (`head->next == NULL`), there is no need to remove duplicates. The function returns the head as it is.

2. **Start from the Second Node:**
   - A pointer `temp` is initialized to point to the second node (`head->next`). This is because the first node doesn't need to be compared with a previous node, as there is no earlier node for it.

3. **Traverse the List:**
   - The function enters a loop that iterates through the list using the pointer `temp` until it reaches the end (`temp == NULL`).

4. **Check for Duplicates:**
   - For each node, the function checks if its `data` is equal to its previous node's `data` (`temp->data == temp->prev->data`).
   - If this condition is true, it means the current node is a duplicate of the previous node.

5. **Remove the Duplicate Node:**
   - If a duplicate is found:
     - The node to be removed is pointed to by `temp`, and it is stored in `nodeToRemove`.
     - The pointers of the neighboring nodes are updated:
       - `nodeToRemove->prev->next` is updated to bypass the node and point to the next node (`nodeToRemove->next`).
       - If `nodeToRemove->next` is not `NULL`, its `prev` pointer is updated to bypass the removed node and point to `nodeToRemove->prev`.
     - The duplicate node (`nodeToRemove`) is deleted to free up memory.
   - After deleting the node, `temp` is updated to point to the next node (`temp = temp->next`) to continue the process.

6. **If No Duplicates Are Found:**
   - If `temp->data != temp->prev->data`, it means the current node is not a duplicate. The function simply moves `temp` to the next node (`temp = temp->next`) and continues the iteration.

7. **Return the Modified List:**
   - Once the list has been fully traversed and all duplicates are removed, the function returns the modified list starting from `head`.

### Key Points:
- The list is **sorted**, which allows for a simple check of consecutive nodes to identify duplicates.
- **Efficient removal**: The function modifies the pointers of the neighboring nodes to remove the duplicate, ensuring that no extra passes are needed to maintain the list structure.
- **Memory deallocation**: The memory of the duplicate node is properly deallocated using `delete`.

### Time Complexity:
- The function makes a single pass through the list, visiting each node exactly once. Therefore, the time complexity is **O(n)**, where `n` is the number of nodes in the list.

### Space Complexity:
- The space complexity is **O(1)**, as the function uses a constant amount of extra space regardless of the size of the input list.

### Summary:
This approach efficiently removes all duplicates from a sorted doubly linked list while maintaining the correct structure of the list. By only adjusting the `next` and `prev` pointers when duplicates are found, it ensures that no unnecessary operations are performed.
*/

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        if (head==NULL || head->next==NULL){
            return head;
        }
        
        struct Node* temp = head->next;
        
        while(temp!=NULL){
            if (temp->data == temp->prev->data){
                struct Node* nodeToRemove = temp;
                temp = temp->next;
                nodeToRemove->prev->next = nodeToRemove->next;
                if (temp!=NULL) temp->prev = nodeToRemove->prev;
                delete nodeToRemove;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};