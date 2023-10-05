/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// APPROACH 1-------->>(optimized)  T.C.->O(n), S.C.->O(1)

class Solution {
private:
    // Function to find the middle node of the linked list
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        // Move the slow pointer by one and the fast pointer by two until
        // the fast pointer reaches the end of the list or goes out of bounds.
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        // Traverse the list, reversing the direction of links
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    // Function to check whether the list is a palindrome
    bool isPalindrome(Node* head) {
        // If the list has only one node, it is always a palindrome
        if (head->next == nullptr) {
            return true;
        }

        // Find the middle node of the linked list
        Node* mid = getMid(head);

        // Reverse the second half of the linked list
        Node* temp = mid->next;
        mid->next = reverse(temp);

        // Pointers to traverse the first and reversed second halves
        Node* head1 = head;
        Node* head2 = mid->next;

        // Compare the elements of the first and reversed second halves
        while (head2 != nullptr) {
            if (head1->data != head2->data) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Reverse the second half back to restore the original linked list
        temp = mid->next;
        mid->next = reverse(temp);

        // The linked list is a palindrome
        return true;
    }
};


// APPROACH 1-------->>  T.C.->O(n), S.C.->O(n)

#include<vector>
// Definition of the Solution class
class Solution {
private:
    // Function to check if a vector is a palindrome
    bool checkPalindrome(std::vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;

        // Loop through the vector from both ends towards the center
        while (start < end) {
            // If the elements at the current positions are not equal, return false
            if (arr[start] != arr[end])
                return false;

            // Move the start and end indices towards the center
            start++;
            end--;
        }

        // The vector is a palindrome
        return true;
    }

public:
    // Function to check whether the linked list is a palindrome
    bool isPalindrome(Node* head) {
        // Create a vector to store the elements of the linked list
        std::vector<int> arr;

        // Traverse the linked list and store its elements in the vector
        Node* temp = head;
        while (temp != nullptr) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        // Call the checkPalindrome function to determine if the vector is a palindrome
        return checkPalindrome(arr);
    }
};
