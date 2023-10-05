#include <bits/stdc++.h> 
/****************************************************************
    Following is the Linked List node structure

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


// Function to reverse every k nodes in a linked list
Node* kReverse(Node* head, int k) {
    // Check if the list is empty
    if (head == NULL) {
        return NULL;
    }

    int len = 0;        // Variable to store the length of the linked list
    Node* temp = head;  // Temporary pointer for traversing the linked list

    // Calculate the length of the linked list
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    // If the length is less than k, no reversal is needed
    if (len < k) {
        return head;
    }

    Node* next = NULL;  // Pointer to the next node in the original list
    Node* curr = head;  // Pointer to the current node being processed
    Node* prev = NULL;  // Pointer to the previous node in the reversed section
    int count = 0;      // Counter to track the number of nodes processed

    // Reverse the first k nodes in the linked list
    while (curr != NULL && count < k) {
        next = curr->next;  // Save the next node in the original list
        curr->next = prev;  // Reverse the link by pointing the current node to the previous node
        prev = curr;        // Move the prev pointer to the current node
        curr = next;        // Move the curr pointer to the next node in the original list
        count++;            // Increment the counter
    }

    // Recursively reverse the next k nodes and link the reversed section to the head
    head->next = kReverse(next, k);

    return prev;  // Return the new head of the reversed section
}
