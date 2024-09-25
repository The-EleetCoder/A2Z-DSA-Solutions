/*
https://leetcode.com/problems/copy-list-with-random-pointer/
*/

/*
The provided C++ solution is designed to **deep copy a linked list with random pointers**. Each node in the linked list contains two pointers: `next` (pointing to the next node) and `random` (pointing to any random node in the list or `NULL`). Here's the approach explained step-by-step:

### 1. **Inserting Dummy Nodes Between Original Nodes**
   - The first `while` loop inserts a **new node (copy)** between each original node of the list.
   - For each node in the original list (`temp`), a new node (`newNode`) is created, copying the value of `temp->val`. 
   - The `next` pointer of the new node (`newNode->next`) points to the original node's `next` node (`temp->next`), and the original node (`temp->next`) now points to the new node.
   - After each insertion, `temp` advances by two steps (`temp = temp->next->next`) to skip the newly inserted node and move to the next original node.
   
   **Purpose:** This step interleaves the original list with its copy. Each new node is placed right after its corresponding original node.

   **Example:**
   ```
   Original List: A -> B -> C
   After Step 1:  A -> A' -> B -> B' -> C -> C'
   ```

### 2. **Setting Up the Random Pointers**
   - In the second `while` loop, the `random` pointers of the newly created nodes are correctly set.
   - For each original node (`temp`), its new node (`temp->next`) should have its `random` pointer set to the copy of the node pointed to by the original node's `random` pointer (`temp->random`).
   - If the original node's `random` pointer is `NULL`, the new node's `random` pointer is also set to `NULL`. Otherwise, it points to the new node corresponding to `temp->random` (which is `temp->random->next`).

   **Purpose:** This step assigns the `random` pointers of the copied nodes based on the original nodes' `random` pointers.

   **Example:**
   ```
   Original randoms: A -> C, B -> A, C -> NULL
   After Step 2: A' -> C', B' -> A', C' -> NULL
   ```

### 3. **Restoring the Original List and Extracting the Copied List**
   - The final `while` loop restores the original list by removing the newly inserted nodes from the original list.
   - Simultaneously, it constructs the deep copied list. 
   - A `dummyHead` node is used to help build the copied list. As each copied node is extracted from the interleaved list, it is added to the copied list starting at `dummyHead`.
   - For each original node (`temp`), the corresponding new node (`newNode`) is extracted (`temp->next`), and the `next` pointer of the original node is restored (`temp->next = temp->next->next`).

   **Purpose:** This step separates the two interleaved lists (original and copied) and restores the original list to its original state.

   **Example:**
   ```
   Interleaved List: A -> A' -> B -> B' -> C -> C'
   After Step 3:
   Original List: A -> B -> C
   Copied List:   A' -> B' -> C'
   ```

### Final Result:
After these three steps, the function returns the head of the copied list (`dummyHead->next`).

### Time Complexity:
- The algorithm runs in **O(n)** time, where `n` is the number of nodes in the original list. Each step involves a single pass through the list.

### Space Complexity:
- The algorithm uses **O(1)** extra space, as the copy is made without using additional structures like hash maps. Only the copied nodes are created.

This approach is efficient and minimizes both time and space usage while making a deep copy of a linked list with random pointers.
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==NULL) return head;

        // inseting dummy node between the original nodes
        Node* temp = head;
        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        // placing the random pointers of dummyNodes to their correct position
        temp = head;
        while(temp!=NULL){
            if (temp->random==NULL) {
                temp->next->random = NULL;    
            } else {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // removing the dummy nodes from the original list;
        temp = head;
        Node* dummyHead = new Node(-1);
        Node* dummyTemp = dummyHead;

        while(temp!=NULL){
            Node* newNode = temp->next;
            temp->next = temp->next->next;
            dummyTemp->next = newNode;
            dummyTemp = dummyTemp->next;
            temp = temp->next;
        }
        return dummyHead->next;
    }
};