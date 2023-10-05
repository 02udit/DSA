#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<T>* solve(Node<T>*& head1, Node<T>*& head2) {
    // If the first linked list has only onle node, append the second linked list to it
    if (head1->next == nullptr) {
        head1->next = head2;
        return head1;
    }

    Node<T>* curr1 = head1;
    Node<T>* next1 = head1->next;
    Node<T>* curr2 = head2;
    Node<T>* next2 = head2->next;

    // Iterate over both linked lists and merge them in sorted order
    while (next1 != nullptr && curr2 != nullptr) {
        // If the data of the current node in the second list is between
        // the data of the current and next nodes in the first list, insert
        // the current node from the second list between them.
        if (curr2->data >= curr1->data && curr2->data <= next1->data) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // Move to the next nodes in both lists
            curr1 = curr2;
            curr2 = next2;
        } else {
            // Move to the next nodes in the first list
            curr1 = next1;
            next1 = next1->next;

            // If we reach the end of the first list, append the rest of
            // the second list to the end of the first list and return.
            if (next1 == nullptr) {
                curr1->next = curr2;
                return head1;
            }
        }
    }
    return head1;
}

Node<T>* sortTwoLists(Node<T>* first, Node<T>* second) {
    // If the first linked list is empty, return the second linked list
    if (first == nullptr) return second;
    
    // If the second linked list is empty, return the first linked list
    if (second == nullptr) return first;

    // Determine the order of merging based on the 1st node data
    if (first->data <= second->data) {
        return solve(first, second);
    } else {
        return solve(second, first);
    }
}



