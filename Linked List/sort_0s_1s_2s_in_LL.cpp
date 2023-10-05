/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

// APPROACH 1--------------->>>>>>(counting and replacing data) O(n)

Node* sortList(Node* head) {
    // Count the occurrences of 0, 1, and 2 in the linked list
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    // Counting the occurrences of 0, 1, and 2
    while (temp != nullptr) {
        if (temp->data == 0) {
            zeroCount++;
        } else if (temp->data == 1) {
            oneCount++;
        } else {
            twoCount++;
        }
        temp = temp->next;
    }

    // Reset temp pointer to the head for modification
    temp = head;

    // Modify the linked list in place based on the counts
    while (temp != nullptr) {
        if (zeroCount != 0) {
            // If there are remaining 0s, set the current node's data to 0
            temp->data = 0;
            zeroCount--;
        } else if (oneCount != 0) {
            // If there are remaining 1s, set the current node's data to 1
            temp->data = 1;
            oneCount--;
        } else {
            // If there are remaining 2s, set the current node's data to 2
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next; // Move to the next node
    }

    // Return the head of the modified linked list
    return head;
}


// APPROACH 2--------------->>>>>>(without replacing data) O(n)


void insertAtTail(Node*& tail, Node* curr) {
    // Connect the current node to the tail and update the tail pointer
    tail->next = curr;
    tail = tail->next;
}

Node* sortList(Node* head) {
    // Create three dummy heads for 0s, 1s, and 2s
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    // Traverse the original linked list
    while (curr != nullptr) {
        int value = curr->data;

        // Insert the current node into the corresponding bucket based on its value
        if (value == 0) {
            insertAtTail(zeroTail, curr);
        } else if (value == 1) {
            insertAtTail(oneTail, curr);
        } else {
            insertAtTail(twoTail, curr);
        }

        // Move to the next node in the original linked list
        curr = curr->next;
    }

    // Connect the buckets (0s, 1s, 2s) to form the sorted linked list
    if (oneHead->next != nullptr) { //1s list is not empty
        zeroTail->next = oneHead->next;
    } else {  // 1s list is empty
        zeroTail->next = twoHead->next; 
    }
    oneTail->next = twoHead->next;
    twoTail->next = nullptr;

    // Update the head pointer to point to the beginning of the sorted linked list
    head = zeroHead->next;

    // Delete the dummy heads to avoid memory leaks
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    // Return the head of the modified linked list
    return head;
}






