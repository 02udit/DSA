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

// APPROACH 1------------>>(iteratively)

// Function to reverse a linked list
Node *reverseLinkedList(Node *head) 
{
    // Check if the list is empty or has only one element
    if(head == NULL || head->next == NULL){
        return head; // If so, the list is already reversed or doesn't need reversal
    }
    Node* prev = NULL; // Pointer to the previous node (initialized to NULL as it's the end of the reversed list)
    Node* curr = head; // Pointer to the current node (starting from the head of the original list)
    Node* forward = NULL; // Pointer to the next node in the original list

    // Traverse the original list
    while(curr != NULL) {
        forward = curr->next; // Save the next node in the original list before changing the link
        curr->next = prev; // Reverse the link by pointing the current node to the previous node

        // Move the pointers forward for the next iteration
        prev = curr; // Move the previous pointer to the current node
        curr = forward; // Move the current pointer to the next node in the original list
    }
    return prev; // 'prev' is now pointing to the new head of the reversed list
}


// APPROACH 2------------>>(recursively)

// Recursive helper function to reverse a linked list
void reverse(Node*& head, Node*& prev, Node*& curr) {
    // Base case: If the current node is NULL, the end of the list is reached
    if (curr == NULL) {
        head = prev; // Update the head of the reversed list to the last non-NULL node
        return;      // Return to the previous recursive call
    }

    Node* forward = curr->next; // Save the next node in the original list before changing the link

    // Recursive call: Move to the next node and update pointers
    reverse(head, curr, forward);

    curr->next = prev; // Reverse the link by pointing the current node to the previous node
}

// Function to initiate the linked list reversal using the reverse helper function
Node* reverseLinkedList(Node* head) {
    Node* prev = NULL; // Pointer to the previous node (initialized to NULL as it's the end of the reversed list)
    Node* curr = head; // Pointer to the current node (starting from the head of the original list)

    // Call the recursive helper function to reverse the linked list
    reverse(head, prev, curr);

    return head; // Return the head of the reversed list
}



// APPROACH 3------------>>(recursively)

// Recursive helper function to reverse a linked list
Node* reverse(Node*& head) {
    // Base case: If the list is empty or has only one element, it is already reversed
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursive call: Reverse the rest of the list starting from the next node
    Node* newHead = reverse(head->next);

    head->next->next = head; // Reverse the link by pointing the next node's next to the current node
    head->next = NULL;       // Set the next of the current node to NULL to complete the reversal

    return newHead; // Return the new head of the reversed list
}

// Function to initiate the linked list reversal using the reverse helper function
Node* reverseLinkedList(Node* head) {
    return reverse(head); // Call the reverse helper function and return the head of the reversed list
}
