/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

// Sorted LL------------>>

Node* uniqueSortedList(Node* head) {
    // If the linked list is empty or has only one node, no duplicates to remove
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Pointer to traverse the linked list
    Node* curr = head;

    // Traverse the linked list until the second-to-last node
    while (curr->next != nullptr) {
        // Check if the current node's data is equal to the next node's data
        if (curr->data == curr->next->data) {
            // Duplicate found, remove the next node
            Node* nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete nodeToDelete;  // Free the memory of the duplicate node
        } else {
            // Move to the next node if no duplicate is found
            curr = curr->next;
        }
    }

    // Return the head of the modified linked list
    return head;
}



// Unsorted LL------------>>

// approach1-->> use 2 loops   T.C.->[O(n^2)]
// approach2-->> sort LL and use the previous approach [O(nlogn)]
// approach3-->> use map to check visited [O(n)]

Node* removeDuplicates(Node* head) {
    // If the linked list is empty, no duplicates to remove
    if (head == nullptr) {
        return head;
    }

    // Map to keep track of visited elements (key: element value, value: boolean)
    std::map<int, bool> visited;

    // Pointers for traversal and keeping track of the previous node
    Node* curr = head;
    Node* prev = nullptr;

    // Traverse the linked list
    while (curr != nullptr) {
        // Check if the current data value has been visited
        if (visited[curr->data] == true) {
            // Duplicate found, remove the current node
            prev->next = curr->next;
            delete curr;  // Free the memory of the duplicate node
            curr = prev->next;  // Move to the next node after the duplicate
        } else {
            // Mark the current data value as visited
            visited[curr->data] = true;
            // Move to the next node while updating the pointers
            prev = curr;
            curr = curr->next;
        }
    }

    // Return the head of the modified linked list
    return head;
}