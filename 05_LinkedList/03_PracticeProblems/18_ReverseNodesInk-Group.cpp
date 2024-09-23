/*
https://leetcode.com/problems/reverse-nodes-in-k-group/
*/

/*
The problem you're solving involves reversing nodes in groups of `k` in a linked list. Let's break down the approach used in the code.

### Key Functions:
1. **`reverseLinkedList`**:
    - This function takes the head of a linked list (or a portion of it) and reverses it in place.
    - It uses three pointers: 
        - `temp` to traverse the list.
        - `prev` to track the reversed portion.
        - `front` to temporarily store the next node in the original list to move forward.
    - The loop runs until all nodes are reversed, and it returns the new head of the reversed portion (i.e., the last node of the original sublist).

2. **`getKthNode`**:
    - This function retrieves the `k`-th node from the current starting node (`temp`).
    - It decrements `k` as it moves forward in the list.
    - It returns the pointer to the `k`-th node, or `NULL` if the list has fewer than `k` nodes remaining.

### `reverseKGroup` Approach:

This is the core function that handles the process of reversing nodes in groups of `k`.

1. **Initial Setup**:
    - `temp` starts at the head of the list, which will be used to iterate through the list.
    - `prevLast` is initialized as `NULL`. This keeps track of the last node of the previous reversed group, allowing the reversed groups to be linked together.

2. **Main Loop**:
    - **Finding the k-th Node**: For each iteration, the function uses `getKthNode(temp, k)` to find the `k`-th node from the current `temp`. If the list has fewer than `k` nodes remaining, the loop exits, as we do not reverse a group with fewer than `k` nodes.
    
    - **Breaking and Reversing**: 
        - The next node after the `k`-th node (`kThNode->next`) is stored in `nextNode`. This is the node that will be processed in the next group.
        - The `k`-th node’s `next` pointer is set to `NULL`, breaking the current group from the rest of the list.
        - The group starting at `temp` is then reversed using `reverseLinkedList(temp)`. After reversing, `temp` will be the last node of the reversed group.
    
    - **Updating Pointers**:
        - If `temp == head`, meaning it's the first group, then the `head` pointer of the list is updated to point to the new head of the reversed group, which is `kThNode`.
        - Otherwise, the last node of the previous group (`prevLast`) is connected to the new head of the reversed group (`kThNode`).
    
    - **Advancing**:
        - `prevLast` is updated to `temp`, which is now the last node of the reversed group.
        - `temp` is updated to `nextNode` to start processing the next group.

3. **Final Linking**:
    - If the function encounters a group with fewer than `k` nodes, it simply connects the last node of the previous group to the remaining nodes (if any), which will not be reversed.

### Time Complexity:
- The function visits each node of the list exactly twice:
  1. Once for finding the `k`-th node.
  2. Once for reversing the group.
Thus, the overall time complexity is \( O(n) \), where \( n \) is the number of nodes in the list.

### Space Complexity:
- Since the reversal is done in place, the space complexity is \( O(1) \), excluding the space used for recursion or stack frames.

### Summary:
- The approach divides the linked list into groups of `k` nodes, reverses each group, and links them back together.
- If the remaining nodes are fewer than `k`, they are left unchanged.
*/

class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    // Function to get the Kth ListNode from a given position in the linked list
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {
            ListNode* kThNode = getKthNode(temp, k);
            if (kThNode == NULL) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }
            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;
            reverseLinkedList(temp);
            if (temp == head) {
                head = kThNode;
            } else {
                prevLast->next = kThNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};