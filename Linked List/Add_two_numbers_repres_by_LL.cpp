/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
// Definition of the Solution class
class Solution {
private:
    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        
        // Traverse the linked list, reversing the next pointers
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Return the new head of the reversed linked list
        return prev;
    }

    // Function to insert a new node at the tail of a linked list
    void insertAtTail(Node* &head, Node* &tail, int value) {
        Node* temp = new Node(value);
        
        // If the list is empty, set the new node as both head and tail
        if (head == nullptr) {
            head = temp;
            tail = temp;
            return;
        } else {
            // Otherwise, append the new node to the tail
            tail->next = temp;
            tail = temp;
        }
    }

    // Function to add two linked lists representing numbers
    Node* add(Node* first, Node* second) {
        int carry = 0;
        Node* ansHead = nullptr;
        Node* ansTail = nullptr;

        // Loop until both linked lists are processed and there is no carry
        while (first != nullptr || second != nullptr || carry != 0) {
            // Extract values of the current nodes or assume 0 if the node is nullptr
            int val1 = (first != nullptr) ? first->data : 0;
            int val2 = (second != nullptr) ? second->data : 0;

            // Calculate the sum of current digits and the carry
            int sum = carry + val1 + val2;
            int digit = sum % 10;

            // Insert the new digit at the tail of the result linked list
            insertAtTail(ansHead, ansTail, digit);

            // Update carry for the next calculation
            carry = sum / 10;

            // Move to the next nodes in both linked lists if they exist
            if (first != nullptr) first = first->next;
            if (second != nullptr) second = second->next;
        }

        // Return the head of the result linked list
        return ansHead;
    }

public:
    // Function to add two numbers represented by linked lists.
    Node* addTwoLists(Node* first, Node* second) {
        // Reverse the input linked lists to facilitate addition
        first = reverse(first);
        second = reverse(second);

        // Perform addition on reversed linked lists
        Node* ans = add(first, second);

        // Reverse the result to obtain the final answer
        ans = reverse(ans);

        // Return the head of the result linked list
        return ans;
    }
};
