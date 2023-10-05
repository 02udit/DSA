/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
// Function to detect the presence of a loop in a linked list using Floyd's Cycle Detection Algorithm
Node* detectionOfLoop(Node* head) {
    // Check if the list is empty
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;  // Slow pointer initially at the head
    Node* fast = head;  // Fast pointer initially at the head

    // Traverse the linked list using Floyd's Cycle Detection Algorithm
    while (slow != NULL && fast != NULL) {
        fast = fast->next;  // Move the fast pointer one step
        if (fast != NULL) {
            fast = fast->next;  // Move the fast pointer one more step
        }
        slow = slow->next;  // Move the slow pointer one step

        // Check if the slow and fast pointers meet, indicating the presence of a loop
        if (slow == fast) {
            return slow;  // Return the node where the pointers meet (an intersection point in the loop)
        }
    }

    return NULL;  // No loop is detected
}

// Function to find the starting point of the loop in a linked list
Node* getStartOfLoop(Node* head) {
    // Check if the list is empty
    if (head == NULL) {
        return NULL;
    }

    Node* intersection = detectionOfLoop(head);  // Get the intersection point in the loop

    // If there is no loop, or the intersection point is not found, return NULL
    if (intersection == NULL) {
        return NULL;
    }

    Node* slow = head;  // Slow pointer initially at the head

    // Move one pointer from the head and another from the intersection point until they meet
    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;  // Return the starting point of the loop
}

// Function to remove the loop in a linked list
Node* removeLoop(Node* head) {
    // Check if the list is empty
    if (head == NULL) {
        return NULL;
    }

    Node* startOfLoop = getStartOfLoop(head);  // Get the starting point of the loop

    // If there is no loop, return the original head
    if (startOfLoop == NULL) {
        return head;
    }

    Node* temp = startOfLoop;

    // Traverse until the node whose next points to the starting point of the loop
    while (temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL;  // Remove the loop by breaking the link

    return head;  // Return the head of the list after removing the loop
}

/************************************************************************/













// -------->>>>>>> short and precise code for removing loop:-

Node* removeLoopTwoPointers(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Detect the loop using the Tortoise and Hare algorithm
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop detected, find the starting point of the loop
            slow = head;
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            // Break the loop by setting the next of the node before the starting point to null
            fast->next = nullptr;
            break;
        }
    }

    return head;
}

