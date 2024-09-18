/*
https://www.geeksforgeeks.org/problems/find-length-of-loop/1
*/

/*
This solution is designed to find the length of a loop in a linked list using Floyd's Cycle Detection Algorithm. The algorithm starts with two pointers, `slow` and `fast`, both initialized to the head of the list. The `slow` pointer moves one step at a time, while the `fast` pointer moves two steps at a time. If a cycle exists, the `slow` and `fast` pointers will eventually meet. Once they meet, the code shifts the `fast` pointer by one node, and a counter (`count`) is initialized to 1. Then, the `fast` pointer is moved around the loop one step at a time until it meets the `slow` pointer again, incrementing the counter at each step. The function returns the total count, which represents the length of the loop. If no cycle is detected, the function returns `0`.
*/

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast==slow){
                fast = fast->next;
                int count = 1;
                while(slow!=fast){
                    fast = fast->next;
                    count++;
                }
                return count;
            }
        }
        return 0;
    }
};