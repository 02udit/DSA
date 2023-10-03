#include<bits/stdc++.h>
using namespace std;

// Node class representing each element in the linked list
class Node {
public:
    int data;        // Data of the node
    Node* next;      // Pointer to the next node in the list

    // Constructor to initialize the node with given data
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    // Destructor (commented out due to potential issues, explained below)
    /*~Node(){
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }*/
    // Explanation: The destructor attempts to recursively delete the next node,but this approach can lead to stack overflow for long lists and is generally considered a less optimal way of deallocating memory. Also, setting this->next to NULL after deletion may not be necessary, as the pointer should already be dangling after the delete operation.

};

// Function to insert a node at the head of the linked list
void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);  // Create a new node with the given data
    temp->next = head;            // Set the new node's next pointer to the current head
    head = temp;                  // Update the head to be the new node
}

// Function to insert a node at the tail of the linked list
void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);  // Create a new node with the given data
    tail->next = temp;            // Set the current tail's next pointer to the new node
    tail = temp;                  // Update the tail to be the new node
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    if (position == 1) {
        insertAtHead(head, data);  // If position is 1, insert at the head
        return;
    }
    Node* temp = head;
    int count = 1;
    while (count < position - 1) {
        temp = temp->next;         // Traverse to the node before the desired position
        count++;
    }
    if (temp->next == NULL) {
        insertAtTail(tail, data);  // If the position is at the end, insert at the tail
        return;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;  // Insert the new node between temp and temp->next
    temp->next = nodeToInsert;
}

// Function to delete a node with a specific value from the linked list
void deleteNode(Node* &head, Node* &tail, int value) {
    if (value == head->data) {
        Node* temp = head;
        head = head->next;          // Update the head to skip the node being deleted
        delete temp;                // Delete the node
    } else {
        Node* curr = head;
        Node* prev = NULL;

        while (value != curr->data) {
            prev = curr;
            curr = curr->next;      // Traverse to the node with the specified value
        }
        prev->next = curr->next;    // Update the previous node's next pointer to skip the node being deleted
        if (curr->next == NULL) {
            tail = prev;             // If the deleted node was the tail, update the tail
        }
        delete curr;                 // Delete the node
    }
}

// Function to print the elements of the linked list
void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";  // Print the data of each node
        temp = temp->next;           // Move to the next node
    }
    cout << endl;
}

int main() {
    // Creating the first node and initializing head and tail
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;

    //NOTE: we can handle empty list case same as done in doubly LL

    // Inserting nodes at the head
    insertAtHead(head, 8);
    insertAtHead(head, 16);
    print(head);

    // Inserting nodes at the tail
    insertAtTail(tail, 20);
    insertAtTail(tail, 40);
    print(head);

    // Inserting a node at a specific position
    insertAtPosition(head, tail, 3, 100);
    print(head);

    // Deleting a node with a specific value
    deleteNode(head, tail, 5);
    print(head);

    // Printing the head and tail values
    cout << "head = " << head->data << endl;
    cout << "tail = " << tail->data << endl;

    return 0;
}
