#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/
// APPROACH 1------------>>>>

// Function to check if a linked list is circular
bool isCircular(Node* head) {
    // Check if the list is empty or contains only one node pointing to itself
    if (head == NULL || head->next == head) {
        return true;
    }

    // Check if the list has only one node (not pointing to itself)
    if (head->next == NULL) {
        return false;
    }

    Node* temp = head; // Temporary pointer for traversing the linked list

    // Traverse the linked list marking visited nodes
    while (temp != NULL && temp->data != 0) {
        temp->data = 0;  // Mark the current node as visited
        temp = temp->next; // Move to the next node
    }

    // Check if the traversal reached the end of the list (not circular)
    if (temp == NULL) {
        return false;
    }

    // Check if the last node is marked as visited (circular) and not the head (means loop is present but but not circular)
    if (temp->data == 0 && temp != head) {
        return false;
    }

    // The list is circular
    return true;
}


// APPROACH 2------------>>>>

// Function to check if a linked list is circular using Floyd's Cycle Detection Algorithm
bool isCircular(Node* head) {
    // Check if the list is empty, consider it circular
    if (head == NULL) {
        return true;
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

        // Check if the slow and fast pointers meet
        if (slow == fast && slow == head) {
            return true;  // The list is circular, and the pointers have met at the head
        } else if (slow == fast && slow != head) {
            return false;  // The list is circular, but the pointers have not met at the head
        }
    }

    return false;  // The list is not circular
}


