/*
https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
*/

/*
This approach is designed to flatten a linked list where each node has two pointers: one to the next node (`next`) and another to a bottom node (`bottom`). The goal is to flatten the list such that all nodes are merged into a single list sorted by the `bottom` pointers.

### Breakdown of the code:

1. **The `merge` function**:
   - The `merge` function merges two sorted linked lists (`head1` and `head2`), which are connected through their `bottom` pointers.
   - A dummy node (`dummyNode`) is used to simplify edge cases when building the merged list.
   - Two pointers, `temp1` and `temp2`, are initialized to the heads of the two lists (`head1` and `head2`).
   - The function compares the `data` values of the nodes from both lists and links the smaller node to the `bottom` of the current list (`temp->bottom`). It then moves the pointer (`temp`, `temp1`, or `temp2`) forward.
   - If one of the lists reaches the end (i.e., becomes `NULL`), the remaining portion of the other list is appended directly to the result.
   - Finally, the function returns `dummyNode->bottom`, which is the head of the merged, sorted list.

2. **The `flatten` function**:
   - This function recursively flattens the entire linked list by merging the current list (`root`) with the list obtained by flattening `root->next`.
   - The base case is when there is no further list to flatten (`temp->next == NULL`), in which case the function returns `temp`, i.e., the last list.
   - After recursively flattening the list, it merges the current list (`temp`) with the flattened list (`head2`), effectively combining them into a single sorted list using the `merge` function.

### Key Points:

- **Recursive Flattening**: The `flatten` function works recursively to flatten the `next` lists first, then merges them with the current list. This ensures that when merging, both lists are already sorted by their `bottom` pointers.
  
- **Merging Two Sorted Lists**: The `merge` function combines two lists in a way similar to the merge step in merge sort, ensuring that the result is sorted.

- **Bottom Pointer as the Primary Connector**: Since the final result should be a flattened list connected through `bottom` pointers, the `next` pointers are effectively disregarded after the merging.
```
*/

class Solution {
  public:
    Node* merge(Node* head1, Node* head2){
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while(temp1!=NULL && temp2!=NULL){
            if (temp1->data < temp2->data){
               temp->bottom = temp1;
               temp = temp->bottom;
               temp1 = temp1->bottom;
            } else {
               temp->bottom = temp2;
               temp = temp->bottom;
               temp2 = temp2->bottom;                
            }
        }
        
        if (temp1!=NULL){
            temp->bottom = temp1;
        } else {
            temp->bottom = temp2;
        }
        
        return dummyNode->bottom;
    }
  
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        Node* temp = root;
        
        if (temp->next==NULL){
            return temp;
        }
        
        Node* head2 = flatten(root->next);
        
        return merge(temp, head2);
    }
};