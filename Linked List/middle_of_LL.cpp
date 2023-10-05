#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

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

*****************************************************************/

// APPROACH 1---------------->>>>

// Function to get the length (number of nodes) of a linked list
int getLength(Node* head) {
    int len = 0; // Initialize length to 0
    while (head != NULL) {
        len++;      // Increment length for each node
        head = head->next; // Move to the next node
    }
    return len; // Return the length of the linked list
}

// Function to find the middle node of a linked list
Node* findMiddle(Node* head) {
    int len = getLength(head); // Get the length of the linked list
    int position = (len / 2) + 1; // Calculate the position of the middle node
    int count = 1; // Initialize a counter to track the current position
    Node* temp = head; // Create a temporary pointer to traverse the linked list

    // Traverse the linked list to find the middle node
    while (count < position) {
        temp = temp->next; // Move to the next node
        count++; // Increment the counter
    }

    return temp; // Return the pointer to the middle node
}


// APPROACH 2---------------->>>>

// Function to get the middle node of a linked list using the two-pointer technique
Node* getMiddle(Node* &head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head; // Return the head as the middle node in this case
    }

    Node* slow = head;        // Slow pointer initially at the head
    Node* fast = head->next;  // Fast pointer initially one step ahead of the head

    // Traverse the linked list using the two-pointer technique
    while (fast != NULL) {
        fast = fast->next;     // Move the fast pointer one step
        if (fast != NULL) {
            fast = fast->next; // Move the fast pointer one more step
        }
        slow = slow->next;     // Move the slow pointer one step
    }

    return slow; // Return the slow pointer, which is now pointing to the middle node
}

// Function to find the middle node of a linked list
Node* findMiddle(Node* head) {
    return getMiddle(head); // Call the getMiddle function and return the result
}
