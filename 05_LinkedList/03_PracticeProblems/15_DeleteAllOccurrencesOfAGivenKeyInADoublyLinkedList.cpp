/*
https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461
*/

/*
The provided code defines a function `deleteAllOccurrences` to remove all occurrences of a specific value `k` from a doubly linked list. Here’s an explanation of the approach:

### Approach:

1. **Initial Null Check:**
   The function first checks if the list is empty (i.e., `head == NULL`). If true, it returns `NULL`, as there is nothing to delete.

2. **Delete Occurrences at the Head:**
   - The list may have occurrences of `k` starting from the head. 
   - The first `while` loop handles the case where multiple nodes at the head of the list contain the value `k`.
   - It iterates over the nodes at the head, deleting each one where `temp->data == k`.
   - Each deleted node’s memory is freed (`delete toDelete`), and the head is updated to the next node.
   - If the new `head` node is not `NULL`, its `prev` pointer is set to `NULL` to detach it from the old head.

3. **Delete Occurrences in the Middle or End:**
   - After handling the head, the code enters another `while` loop to traverse the remaining nodes of the list.
   - For each node:
     - If the node’s data is equal to `k`, it is deleted by adjusting the pointers of the previous (`temp->prev`) and next (`temp->next`) nodes.
     - The `prev` node's `next` pointer is updated to skip the current node, and the `next` node's `prev` pointer is updated to bypass the current node.
     - The current node is then deleted and the loop moves to the next node (`temp = temp->next`).
   - If the node does not contain `k`, it simply moves to the next node without deletion.

4. **Return Updated Head:**
   Once the function completes, the modified list’s head is returned. This head could be `NULL` if all nodes were deleted, or it could point to the new head if some nodes remain.

### Key Points:
- The code ensures that all occurrences of `k` in the list, including at the head, middle, and tail, are deleted.
- It efficiently updates the `next` and `prev` pointers of neighboring nodes to maintain the structure of the doubly linked list.
- Memory is properly freed for every deleted node using `delete`.

This approach ensures that the entire list is scanned and all nodes with the value `k` are removed, leaving the rest of the list intact.
*/

Node* deleteAllOccurrences(Node* head, int k) {
    if (head == NULL) return NULL; // If the list is empty, return NULL

    Node* temp = head;

    // Delete all occurrences of k at the head of the list
    while (temp != NULL && temp->data == k) {
        Node* toDelete = temp;
        temp = temp->next; // Move to the next node
        if (temp != NULL) {
            temp->prev = NULL; // Detach the new head from the deleted node
        }
        delete toDelete; // Free the memory of the deleted node
        head = temp; // Update the head
    }

    // Traverse the list and delete occurrences of k in the middle or end
    while (temp != NULL) {
        if (temp->data == k) {
            Node* toDelete = temp;

            // Adjust the previous and next pointers
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }

            temp = temp->next; // Move to the next node
            delete toDelete; // Free the memory of the deleted node
        } else {
            temp = temp->next; // Move to the next node
        }
    }

    return head; // Return the updated head
}
