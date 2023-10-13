#include<bits/stdc++.h>
using namespace std;

// APPROACH 1------------>>>>>>(using stack)

// Function to interleave the first half of the queue with the second half
void interLeave_1(queue<int>& q) {
    int n = q.size(); // Get the size of the queue
    int mid = n / 2;   // Calculate the midpoint of the queue

    stack<int> s; // Create a stack to temporarily hold elements

    // Push the first half of the queue onto the stack
    for (int i = 0; i < mid; i++) {
        s.push(q.front()); // Push the front element of the queue onto the stack
        q.pop(); // Remove the front element from the queue
    }

    // Pop elements from the stack and enqueue them to the queue
    while (!s.empty()) {
        q.push(s.top()); // Enqueue the top element of the stack
        s.pop(); // Pop the top element from the stack
    }

    // Enqueue the first half of the queue
    for (int i = 0; i < mid; i++) {
        q.push(q.front()); // Enqueue the front element of the queue
        q.pop(); // Remove the front element from the queue
    }
    
    //again Push the first half of the queue onto the stack
    for (int i = 0; i < mid; i++) {
        s.push(q.front()); // Push the front element of the queue onto the stack
        q.pop(); // Remove the front element from the queue
    }
    // Enqueue elements in alternating order (interleave)
    while (!s.empty()) {
        q.push(s.top()); // Enqueue the top element of the stack
        s.pop(); // Pop the top element from the stack
        q.push(q.front()); // Enqueue the front element of the queue
        q.pop(); // Remove the front element from the queue
    }
}


// APPROACH 2------------>>>>>>(using new queue)


// Function to interleave the first half of the queue with the second half
void interLeave_2(queue<int>& q) {
    int n = q.size(); // Get the size of the queue
    int mid = n / 2;   // Calculate the midpoint of the queue

    queue<int> newQ; // Create a new queue to temporarily hold elements

    // Enqueue the first half of the original queue to the new queue
    for (int i = 0; i < mid; i++) {
        newQ.push(q.front()); // Enqueue the front element of the original queue
        q.pop(); // Remove the front element from the original queue
    }

    // Interleave elements from the new queue and the original queue
    while (!newQ.empty()) {
        q.push(newQ.front()); // Enqueue the front element of the new queue to the original queue
        newQ.pop(); // Remove the front element from the new queue
        q.push(q.front()); // Enqueue the front element of the original queue to the original queue
        q.pop(); // Remove the front element from the original queue
    }
}



int main() {
    // Create a queue and enqueue some elements
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    // Call the interLeave_1 function to modify the queue
    interLeave_1(q);
    // Call the interLeave_2 function to modify the queue
    // interLeave_2(q);

    // Print the modified queue
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " "; // Print the front element of the queue
        q.pop(); // Remove the front element from the queue
    }

    return 0;
}
