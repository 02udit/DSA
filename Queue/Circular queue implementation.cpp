#include <bits/stdc++.h> 
using namespace std;

class CircularQueue {
    int* arr;       // Array to store elements in the circular queue
    int front;      // Index pointing to the front of the circular queue
    int rear;       // Index pointing to the rear of the circular queue
    int size;       // Maximum size of the circular queue

public:
    // Constructor to initialize the circular queue with a given size
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;  // Initialize front and rear to -1 to indicate an empty queue
    }

    // Enqueues an element into the circular queue. Returns true if successful, false otherwise.
    bool enqueue(int value) {
        // Check if the circular queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            // Queue is full
            // cout << "Queue is full";
            return false;
        } else if (front == -1) {
            // If the queue is empty, set front and rear to 0
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            // If rear is at the end of the array, but there is space at the front, wrap around
            rear = 0;
        } else {
            // Move the rear pointer to the next position
            rear++;
        }

        // Insert the value at the rear position
        arr[rear] = value;
        return true;
    }

    // Dequeues the front element from the circular queue. Returns -1 if the queue is empty.
    int dequeue() {
        // Check if the circular queue is empty
        if (front == -1) {
            // cout << "Queue is empty" << endl;
            return -1;
        }

        // Retrieve the element at the front
        int ans = arr[front];
        arr[front] = -1;  // Mark the front position as empty

        // Adjust front and rear pointers based on the position of front
        if (front == rear) {
            // If there is only one element in the queue, reset front and rear to -1
            front = rear = -1;
        } else if (front == size - 1) {
            // If front is at the end of the array, wrap around to the beginning
            front = 0;
        } else {
            // Move front to the next position
            front++;
        }

        return ans;
    }
};
