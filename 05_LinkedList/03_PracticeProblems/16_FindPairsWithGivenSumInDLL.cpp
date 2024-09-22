/*
https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
*/

/*
### Explanation of the Approach:

The function `findPairsWithGivenSum` is designed to find all pairs of nodes in a doubly linked list where the sum of the data in the two nodes equals the given target sum. It returns these pairs as a vector of `pair<int, int>`.

### Approach:

1. **Initialize Start and End Pointers:**
   - The function uses two pointers: `start` (initialized to the head of the list) and `end` (also initialized to the head).
   - These pointers will be used to traverse the list, looking for pairs of nodes whose values sum to the target.

2. **Find the End Pointer:**
   - A temporary pointer `temp` is used to move towards the end of the list. It keeps moving until it finds the node whose value is greater than or equal to the target sum.
   - This helps in limiting the search space since any node with data greater than the target won't be useful for pair formation.

3. **Handle Edge Case:**
   - If `temp` reaches `NULL`, it means no node is found with a value less than the target. In this case, there are no valid pairs, and the function returns an empty vector.

4. **Two-Pointer Search for Pairs:**
   - The key logic of the function is based on the two-pointer technique:
     - The `start` pointer moves from the beginning of the list towards the right (next nodes).
     - The `end` pointer moves from the `temp` node towards the left (previous nodes).
   - The sum of the values at the `start` and `end` pointers is calculated. Based on this sum:
     - If the sum equals the target, a valid pair is found. The pair is added to the result vector (`ans`), and both pointers are moved inward (i.e., `start` moves to the next node and `end` moves to the previous node).
     - If the sum is less than the target, `start` is moved to the next node to increase the sum.
     - If the sum is greater than the target, `end` is moved to the previous node to decrease the sum.

5. **Stop Condition:**
   - The loop continues as long as `start->data < end->data`. This ensures that the same pair is not considered multiple times and that the two pointers do not cross each other.

6. **Return the Result:**
   - After the loop completes, the function returns the vector `ans`, which contains all valid pairs of nodes that sum to the target.

### Time Complexity:
- **Time Complexity:** The function traverses the list linearly to find the end node, then uses a two-pointer approach. Hence, the time complexity is `O(n)`, where `n` is the number of nodes in the list.
- **Space Complexity:** The space complexity is `O(n)` due to the vector `ans` that stores the pairs.

### Code Efficiency:
This method efficiently finds the required pairs in one pass through the list with the two-pointer technique, ensuring minimal traversal and comparisons.
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector <pair<int,int>> ans;
        
        Node* start = head;
        Node* end = head;
        
        Node* temp = head;
        while(temp!=NULL && temp->next!=NULL && temp->next->data<target){
            temp = temp->next;
        }
        
        if (temp==NULL) return ans;
        else {
            end = temp;
        }
        
        
        while(start->data < end->data){
            int sum = start->data + end->data;
            if(sum == target){
                ans.push_back({start->data, end->data});
                start = start->next;
                end = end->prev;
            } else if(sum<target){
                start = start->next;
            } else {
                end = end->prev;
            }
        }
        return ans;
    }
};