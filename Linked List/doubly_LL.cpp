#include<bits/stdc++.h>
using namespace std;

// Node class representing each element in the doubly linked list
class Node {
public:
    int data;        // Data of the node
    Node* prev;      // Pointer to the previous node
    Node* next;      // Pointer to the next node

    // Constructor to initialize the node with data and null pointers
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    /*
    // Destructor (commented out due to potential issues)
    ~Node(){
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
    */
};

// Function to print the elements of the linked list
void print(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";   // Print the data of the current node
        temp = temp->next;            // Move to the next node
    }
    cout << endl;
}

// Function to print the elements of the linked list in reverse order
void printReverse(Node*& tail) {
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";   // Print the data of the current node
        temp = temp->prev;            // Move to the previous node
    }
    cout << endl;
}

// Function to get the length of the linked list
int getLength(Node*& head) {
    Node* temp = head;
    int length = 0;
    while (temp != NULL) {
        length++;                     // Increment the length for each node
        temp = temp->next;            // Move to the next node
    }
    return length;
}

// Function to insert a node at the head of the linked list
void insertAtHead(Node*& head, Node*& tail, int data) {
    // if list is empty
    if (head == NULL) {
        Node* temp = new Node(data);  // Create a new node with the given data
        head = temp;                  // Set head and tail to the new node
        tail = temp;
    } else { //if list is not empty
        Node* temp = new Node(data);  // Create a new node with the given data
        temp->next = head;            // Set next of the new node to the current head
        head->prev = temp;            // Set the previous of the current head to the new node
        head = temp;                  // Update the head to the new node
    }
}

// Function to insert a node at the tail of the linked list
void insertAtTail(Node*& tail, Node*& head, int data) {
    // if list is empty
    if (tail == NULL) {
        Node* temp = new Node(data);  // Create a new node with the given data
        tail = temp;                  // Set tail and head to the new node
        head = temp;
    } else { //if list is not empty
        Node* temp = new Node(data);  // Create a new node with the given data
        tail->next = temp;            // Set the next of the current tail to the new node
        temp->prev = tail;            // Set the previous of the new node to the current tail
        tail = temp;                  // Update the tail to the new node
    }
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(Node*& head, Node*& tail, int position, int data) {
    if (position == 1) {
        insertAtHead(head, tail, data); // If position is 1, insert at the head
        return;
    }
    Node* temp = head;
    int count = 1;
    while (count < position - 1) {
        temp = temp->next;             // Move to the node before the specified position
        count++;
    }
    if (temp->next == NULL) {
        insertAtTail(tail, head, data); // If the position is at the end, insert at the tail
        return;
    }
    Node* nodeToInsert = new Node(data); // Create a new node with the given data
    nodeToInsert->next = temp->next;     // Set the next of the new node to the next of the current node
    nodeToInsert->prev = temp;           // Set the previous of the new node to the current node
    temp->next->prev = nodeToInsert;     // Set the previous of the node after insertion point to the new node
    temp->next = nodeToInsert;           // Set the next of the current node to the new node
}

// Function to delete a node with a specific value from the linked list
void deleteNode(Node*& head, Node*& tail, int value) {
    if (head->data == value) {
        Node* temp = head;
        temp->next->prev = NULL;  // Set the previous of the new head to NULL
        head = temp->next;        // Update the head to the next node
        temp->next = NULL;        // Set the next of the deleted node to NULL
        delete temp;              // Delete the node
    } else {
        Node* curr = head;
        Node* prev = NULL;

        while (curr->data != value) {
            prev = curr;
            curr = curr->next;     // Move to the node with the specified value
        }
        if (curr->next == NULL) {
            tail = prev;           // Update the tail if the node to be deleted is the last node
            curr->prev = NULL;     // Set the previous of the deleted node to NULL
            prev->next = curr->next; // Update the next of the previous node to NULL
            curr->next = NULL;       // Set the next of the deleted node to NULL
            delete curr;             // Delete the node
            return;
        }
        curr->prev = NULL;          // Set the previous of the deleted node to NULL
        prev->next = curr->next;    // Update the next of the previous node to the next of the deleted node
        curr->next->prev = prev;    // Set the previous of the node after deletion point to the previous node
        curr->next = NULL;          // Set the next of the deleted node to NULL
        delete curr;                // Delete the node
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting at the head and printing the list
    insertAtHead(head, tail, 10);
    print(head);
    cout << "length of list is: " << getLength(head) << endl;

    // Inserting at the head again and printing the list
    insertAtHead(head, tail, 15);
    print(head);
    cout << "length of list is: " << getLength(head) << endl;

    // Inserting at the tail and printing the list
    insertAtTail(tail, head, 50);
    print(head);
    cout << "length of list is: " << getLength(head) << endl;

    // Inserting at a specific position and printing the list
    insertAtPosition(head, tail, 3, 300);
    print(head);
    cout << "length of list is: " << getLength(head) << endl;

    // Deleting a node and printing the list and its reverse
    deleteNode(head, tail, 300);
    print(head);
    printReverse(tail);
    cout << "length of list is: " << getLength(head) << endl;

    // Printing the head and tail values
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}
