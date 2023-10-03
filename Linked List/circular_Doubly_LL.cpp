#include<bits/stdc++.h>
using namespace std;

// Node class representing each element in the doubly linked circular list
class Node {
public:
    int data;        // Data of the node
    Node* prev;      // Pointer to the previous node
    Node* next;      // Pointer to the next node

    // Constructor to initialize the node with data and null pointers
    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node after a specific element in the doubly linked circular list
void insertNode(Node*& tail, int element, int data) {
    // If the list is empty
    if (tail == NULL) {
        Node* newNode = new Node(data); // Create a new node with the given data
        tail = newNode;                 // Set the tail to the new node
        newNode->next = newNode;        // Set the next of the new node to itself, forming a circular list
        newNode->prev = newNode;        // Set the previous of the new node to itself, forming a circular list
    } else { // If the list is not empty
        Node* curr = tail;
        while (curr->data != element) {
            curr = curr->next;           // Move to the node with the specified element
        }
        Node* newNode = new Node(data);  // Create a new node with the given data
        newNode->next = curr->next;      // Set the next of the new node to the next of the current node
        curr->next->prev = newNode;      // Set the previous of the next node to the new node
        curr->next = newNode;            // Set the next of the current node to the new node
        newNode->prev = curr;            // Set the previous of the new node to the current node
    }
}

// Function to print the elements of the doubly linked circular list
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

// Function to print the elements of the doubly linked circular list in reverse order
void printReverse(Node*& tail) {
    if (tail == NULL) {
        cout << "list is empty " << endl; // Print a message if the list is empty
        return;
    }
    Node* temp = tail;
    cout << "reversed print: ";
    do {
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->prev;          // Move to the previous node
    } while (tail != temp);         // Continue until we reach the tail again
    cout << endl;
}

// Function to delete a node with a specific value from the doubly linked circular list
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
        curr->next->prev = prev; // Update the previous of the next node to the previous of the deleted node
        curr->next = NULL;       // Set the next of the deleted node to NULL
        curr->prev = NULL;       // Set the previous of the deleted node to NULL
        delete curr;             // Delete the node
    }
}

int main() {
    Node* tail = NULL; // Initialize the doubly linked circular list as empty

    // Insert nodes after specific elements and print the list
    insertNode(tail, -1, 7);
    insertNode(tail, 7, 10);
    insertNode(tail, 10, 20);
    print(tail);

    // Insert a node after a specific element and print the list
    insertNode(tail, 7, 30);
    print(tail);
    printReverse(tail);
    cout << "tail: " << tail->data << endl; // Print the current tail

    // Delete a node with a specific value and print the list and its reverse
    deleteNode(tail, 7);
    print(tail);
    printReverse(tail);
    cout << "tail: " << tail->data << endl; // Print the updated tail

    return 0;
}
