#include <bits/stdc++.h> 
using namespace std;

class Queue {
    Queue* head;     // Pointer to the head of the queue
    Queue* tail;     // Pointer to the tail of the queue
    Queue* next;     // Pointer to the next element in the queue
    int data;        // Data of the current element
    
public:
    // Constructor to initialize the queue with null pointers
    Queue() {
        head = NULL;
        tail = NULL;
        next = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    // Check if the queue is empty
    bool isEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    // Enqueue (insert) an element into the queue
    void enqueue(int data) {
        // Create a new node
        Queue* temp = new Queue();
        temp->data = data;

        // If the queue is empty, set both head and tail to the new node
        if (head == NULL) {
            head = temp;
            tail = temp;
        } 
        else {
            // Otherwise, add the new node to the end of the queue and update the tail
            tail->next = temp;
            tail = temp;
        }
    }

    // Dequeue (remove) an element from the front of the queue
    int dequeue() {
        // Check if the queue is empty
        if (head == NULL) {
            return -1;
        }

        // Retrieve the data from the front of the queue
        int value = head->data;

        // Create a temporary pointer to the current head
        Queue* temp = head;

        // Move the head pointer to the next element in the queue
        head = head->next;

        // Disconnect the temporary node from the rest of the queue
        temp->next = NULL;

        // Return the dequeued value
        return value;
    }

    // Get the front element of the queue without removing it
    int front() {
        // Check if the queue is empty
        if (head == NULL) {
            return -1;
        }

        // Return the data from the front of the queue
        return head->data;
    }
};
