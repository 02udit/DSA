#include<bits/stdc++.h>
using namespace std;

// Node class representing each element in the circular linked list
class Node {
public:
    int data;       // Data of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize the node with data and null pointer
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

// Function to insert a node after a specific element in the circular linked list
void insertNode(Node*& tail, int element, int data) {
    // If the list is empty
    if (tail == NULL) {
        Node* newNode = new Node(data); // Create a new node with the given data
        tail = newNode;                 // Set the tail to the new node
        newNode->next = newNode;        // Set the next of the new node to itself, forming a circular list
    } else { // If the list is not empty
        Node* curr = tail;
        while (curr->data != element) {
            curr = curr->next;           // Move to the node with the specified element
        }
        Node* newNode = new Node(data);  // Create a new node with the given data
        newNode->next = curr->next;      // Set the next of the new node to the next of the current node
        curr->next = newNode;            // Set the next of the current node to the new node
    }
}

// Function to print the elements of the circular linked list
void print(Node*& tail) {
    if (tail == NULL) {
        cout << "list is empty " << endl; // Print a message if the list is empty
        return;
    }
    Node* temp = tail;
    do {
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->next;          // Move to the next node
    } while (tail != temp);         // Continue until we reach the tail again
    cout << endl;
}

// Function to delete a node with a specific value from the circular linked list
void deleteNode(Node*& tail, int value) {
    if (tail == NULL) { // Empty list case
        cout << "list is empty, check again " << endl;
    } else {
        Node* prev = tail;
        Node* curr = prev->next;

        while (curr->data != value) {
            prev = curr;
            curr = curr->next; // Move to the node with the specified value
        }

        if (curr == prev) { // Single node/element case
            tail = NULL;
        } else if (curr == tail) { // If deleting node is the tail
            tail = prev;
        }

        prev->next = curr->next; // Update the next of the previous node to the next of the deleted node
        curr->next = NULL;       // Set the next of the deleted node to NULL
        delete curr;             // Delete the node
    }
}

int main() {
    Node* tail = NULL; // Initialize the circular linked list as empty

    // Insert nodes after specific elements and print the list
    insertNode(tail, -1, 7);
    insertNode(tail, 7, 10);
    insertNode(tail, 10, 20);
    print(tail);

    // Insert a node after a specific element and print the list
    insertNode(tail, 7, 30);
    print(tail);
    cout << "tail: " << tail->data << endl; // Print the current tail

    // Delete a node with a specific value and print the list
    deleteNode(tail, 7);
    print(tail);
    cout << "tail: " << tail->data << endl; // Print the updated tail

    return 0;
}
