// Approach 1------------->>
#include <queue>
#include <stack>

class Solution
{
public:
    // Function to reverse the elements of a queue
    queue<int> rev(queue<int> q)
    {
        stack<int> s;

        // Step 1: Push all elements of the queue onto a stack
        while (!q.empty())
        {
            s.push(q.front());
            q.pop();
        }

        // Step 2: Pop elements from the stack and push them back to the queue
        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }

        // Step 3: Return the reversed queue
        return q;
    }
};




// Approach 2------------->>

#include <queue>

class Solution
{
private:
    // Recursive helper function to reverse the elements of a queue
    void sol(queue<int>& q)
    {
        // Base case: if the queue is empty, stop the recursion
        if (q.empty())
            return;

        // Remove the front element from the queue
        int element = q.front();
        q.pop();

        // Recursively reverse the rest of the queue
        sol(q);

        // Push the removed element to the back of the reversed queue
        q.push(element);
    }

public:
    // Function to reverse the elements of a queue
    queue<int> rev(queue<int> q)
    {
        // Call the recursive helper function to reverse the queue
        sol(q);

        // Return the reversed queue
        return q;
    }
};
