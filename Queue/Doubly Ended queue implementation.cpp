#include <bits/stdc++.h>
using namespace std;

class Deque {
    int* arr;       // Array to store elements in the deque
    int front;      // Index pointing to the front of the deque
    int rear;       // Index pointing to the rear of the deque
    int size;       // Maximum size of the deque

public:
    // Constructor to initialize the deque with a given size
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = rear = -1;  // Initialize front and rear to -1 to indicate an empty deque
    }

    // Pushes an element to the front of the deque. Returns true if successful, false otherwise.
    bool pushFront(int x) {
        // Check if the deque is full
        if (isFull()) {
            return false;
        } else if (isEmpty()) {
            // If the deque is empty, set front and rear to 0
            front = rear = 0;
        } else if (front == 0 && rear != size - 1) {
            // If front is at the beginning but there is space at the end, wrap around
            front = size - 1;
        } else {
            // Move front to the previous position
            front--;
        }

        // Insert the value at the front position
        arr[front] = x;
        return true;
    }

    // Pushes an element to the back of the deque. Returns true if successful, false otherwise.
    bool pushRear(int x) {
        // Check if the deque is full
        if (isFull()) {
            return false;
        } else if (isEmpty()) {
            // If the deque is empty, set front and rear to 0
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            // If rear is at the end of the array but there is space at the front, wrap around
            rear = 0;
        } else {
            // Move rear to the next position
            rear++;
        }

        // Insert the value at the rear position
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty.
    int popFront() {
        // Check if the deque is empty
        if (isEmpty()) {
            // cout << "Queue is empty" << endl;
            return -1;
        }

        // Retrieve the element at the front
        int ans = arr[front];
        arr[front] = -1;  // Mark the front position as empty

        // Adjust front and rear pointers based on the position of front
        if (front == rear) {
            // If there is only one element in the deque, reset front and rear to -1
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

    // Pops an element from the back of the deque. Returns -1 if the deque is empty.
    int popRear() {
        // Check if the deque is empty
        if (isEmpty()) {
            // cout << "Queue is empty" << endl;
            return -1;
        }

        // Retrieve the element at the rear
        int ans = arr[rear];
        arr[rear] = -1;  // Mark the rear position as empty

        // Adjust front and rear pointers based on the position of rear
        if (front == rear) {
            // If there is only one element in the deque, reset front and rear to -1
            front = rear = -1;
        } else if (rear == 0) {
            // If rear is at the beginning of the array, wrap around to the end
            rear = size - 1;
        } else {
            // Move rear to the previous position
            rear--;
        }

        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty() {
        if (front == -1) {
            return true;
        } else {
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull() {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1))) {
            return true;
        } else
            return false;
    }
};
