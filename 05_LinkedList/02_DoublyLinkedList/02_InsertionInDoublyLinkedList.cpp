/*
https://www.naukri.com/code360/problems/insertion-in-doubly-linked-list_4609682?leftPanelTabValue=PROBLEM
*/

/*
The insert function in C++ inserts a new node with a specified value at a given position in a doubly linked list. If the position k is 0, the function inserts the new node at the head by updating the next pointer of the new node to the current head and the prev pointer of the old head to the new node, effectively making it the new head of the list. For other positions, the function traverses the list to reach the node just before the insertion point. It then inserts the new node by adjusting the next and prev pointers of the surrounding nodes to maintain the doubly linked structure. If the insertion is not at the end, it also updates the prev pointer of the next node. The function returns the updated head of the list after the insertion.
*/

Node* insert(int k, int val, Node *head) {
    // insert at head (k = 0)
    if (k==0){
        Node* temp = new Node(val);
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }

    // insert at all other positions
    Node* temp = head;

    for (int i=0; i<k-1; i++){
        temp = temp->next;
    }

    Node* ans = new Node(val);
    ans->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = ans;
    ans->prev = temp;
    temp->next = ans;
    return head;
}