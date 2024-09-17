/*
https://www.naukri.com/code360/problems/insertion-in-a-singly-linked-list_4609646
*/

/*
This C++ function insert allows inserting a new node with a specified value into a linked list at a given position. The function accepts four parameters: a pointer to the head of the linked list, the total number of nodes n, the position pos where the new node should be inserted, and the value val of the new node.
If the position is 0, the new node is inserted at the head, making it the new first node.
If the position is anywhere else, the function traverses the list to find the node just before the insertion point, inserts the new node, and updates the pointers accordingly.
Finally, the function returns the updated head of the list.
*/

Node * insert(Node * head, int n, int pos, int val) {
    // insert at head
    if (pos==0){
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        return head;
    }

    // insert anywhere else
    Node* temp = head;
    for (int i=0; i<pos-1; i++){
       temp = temp->next; 
    }

    Node* ans = new Node(val);
    ans->next = temp->next;
    temp->next = ans;

    return head;
}