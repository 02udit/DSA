#include<bits/stdc++.h>
using namespace std;

class kQueue {
    int* arr;     // Array to store elements
    int* front;   // Array to store front pointers for each queue
    int* rear;    // Array to store rear pointers for each queue
    int* next;    // Array to store next indices in the array
    int freeSpot; // Variable to store the index of the next free spot in the array

public:
    // Constructor to initialize the kQueue
    kQueue(int n, int k) {
        arr = new int[n]; // Allocate memory for the array
        front = new int[k]; // Allocate memory for front array
        rear = new int[k]; // Allocate memory for rear array

        // Initialize front and rear pointers for each queue to -1
        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n]; // Allocate memory for next array

        // Initialize the next array to point to the next index
        for (int i = 0; i < n; i++) {
            next[i] = i + 1;
        }

        next[n - 1] = -1; // The last element points to -1
        freeSpot = 0;     // Initialize the free spot index to 0
    }

    // Function to push an element into the kth queue
    void push(int data, int Qn) {
        if (freeSpot == -1) {
            cout << "Queue is full" << endl;
            return;
        }

        int index = freeSpot; // Get the index of the free spot
        freeSpot = next[index]; // Move to the next free spot

        // If the queue is empty, set the front pointer to the new element
        if (front[Qn - 1] == -1) {
            front[Qn - 1] = index;
        } else {
            // Otherwise, link the current rear to the new element
            next[rear[Qn - 1]] = index;
        }

        // Update rear and next pointers
        next[index] = -1;
        rear[Qn - 1] = index;
        arr[index] = data;
    }

    // Function to pop an element from the kth queue
    int pop(int Qn) {
        if (front[Qn - 1] == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int index = front[Qn - 1]; // Get the index of the front element in the queue
        front[Qn - 1] = next[index]; // Move front pointer to the next element
        next[index] = freeSpot; // Update next pointer to the free spot
        freeSpot = index; // Move free spot to the popped element

        return arr[index]; // Return the popped element
    }
};

int main() {
    int k = 3, n = 6;
    kQueue q(n, k); // Create a kQueue object with n elements and k queues

    // Push elements into the queues
    q.push(20, 1);
    q.push(30, 2);
    q.push(40, 3);

    q.push(50, 1);
    q.push(60, 1);
    q.push(100, 3);
    q.push(70, 2);

    // Pop elements from the queues and print the results
    cout << "Pop from Queue 1: " << q.pop(1) << endl;
    cout << "Pop from Queue 2: " << q.pop(2) << endl;
    cout << "Pop from Queue 3: " << q.pop(3) << endl;
    cout << "Pop from Queue 1: " << q.pop(1) << endl;
    cout << "Pop from Queue 2: " << q.pop(2) << endl;
    cout << "Pop from Queue 3: " << q.pop(3) << endl;

    return 0;
}
