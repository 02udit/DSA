#include <bits/stdc++.h> 
using namespace std;

class Queue {
    int* arr;        // Array to store elements in the queue
    int qfront;      // Index pointing to the front of the queue
    int rear;        // Index pointing to the rear of the queue
    int size;        // Maximum size of the queue

public:
    // Constructor to initialize the queue with a default size of 100001
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    // Check if the queue is empty
    bool isEmpty() {
        // If front and rear are equal, the queue is empty
        if (qfront == rear) {
            return true;
        } else {
            return false;
        }
    }

    // Enqueue (insert) an element into the queue
    void enqueue(int data) {
        // Check if the rear has reached the maximum size
        if (rear == size) {
            cout << "Queue is full";
        } else {
            // Insert the element at the rear and move the rear pointer
            arr[rear] = data;
            rear++;
        }
    }

    // Dequeue (remove) an element from the front of the queue
    int dequeue() {
        // Check if the queue is empty
        if (qfront == rear) {
            return -1; // Indicates an empty queue
        } else {
            // Retrieve the element at the front, mark it as -1, and move the front pointer
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            // Reset front and rear pointers if the queue becomes empty after dequeue
            if (qfront == rear) {
                qfront = 0;
                rear = 0;
            }

            return ans;
        }
    }

    // Get the front element of the queue without removing it
    int front() {
        // Check if the queue is empty
        if (qfront == rear) {
            return -1; // Indicates an empty queue
        } else {
            // Return the element at the front
            return arr[qfront];
        }
    }
};
