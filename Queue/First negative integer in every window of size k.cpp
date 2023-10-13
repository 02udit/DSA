#include <vector>
#include <deque>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    // Create a deque to store indices of negative elements in the window
    deque<int> dq;

    // Create a vector to store the final results
    vector<long long> ans;

    // Iterate through the first K elements to populate the deque
    for (int i = 0; i < K; i++) {
        // If the element is negative, add its index to the deque
        if (A[i] < 0) {
            dq.push_back(i);
        }
    }

    // If there are negative elements in the initial window, add the first one to the result vector
    if (!dq.empty()) {
        ans.push_back(A[dq.front()]);
    } else {
        // If no negative elements are found, add 0 to the result vector
        ans.push_back(0);
    }

    // Iterate through the remaining elements from index K to N-1
    for (int i = K; i < N; i++) {
        // Remove elements that are outside the current window from the front of the deque
        if (!dq.empty() && i - dq.front() >= K) {
            dq.pop_front();
        }

        // If the current element is negative, add its index to the deque
        if (A[i] < 0) {
            dq.push_back(i);
        }

        // If there are negative elements in the current window, add the first one to the result vector
        if (!dq.empty()) {
            ans.push_back(A[dq.front()]);
        } else {
            // If no negative elements are found in the current window, add 0 to the result vector
            ans.push_back(0);
        }
    }

    // Return the final result vector
    return ans;
}
