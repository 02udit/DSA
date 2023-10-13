#include <queue>
#include <stack>

using namespace std;

// Function to modify a given queue by reversing the first 'k' elements
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;

    // Step 1: Push the first 'k' elements of the queue onto a stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Pop elements from the stack and push them back to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Rotate the remaining elements in the queue to maintain order
    int n = q.size()-k; // Number of elements in the remaining queue
    for (int i = 0; i < n; i++) {
        q.push(q.front());
        q.pop();
    }

    // Return the modified queue
    return q;
}
