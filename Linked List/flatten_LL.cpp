#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
// Definition of a simple Node class for a linked list with a child pointer

// Function to merge two sorted linked lists
Node* merge(Node* down, Node* right) {
    // Check if either of the lists is empty
    if (down == NULL) {
        return right;
    }
    if (right == NULL) {
        return down;
    }

    // Initialize a new dummy Node for the merged list
    Node* ans = new Node(-1);
    Node* temp = ans;

    // Merge the two lists in sorted order
    while (down != NULL && right != NULL) {
        if (down->data < right->data) {
            // Append the node from 'down' to the merged list
            temp->child = down;
            temp = down;
            down = down->child;
        } else {
            // Append the node from 'right' to the merged list
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }

    // If there are remaining nodes in 'down' or 'right', append them
    if (down != NULL) {
        temp->child = down;
    }
    if (right != NULL) {
        temp->child = right;
    }

    // Skip the dummy node used for initialization
    ans = ans->child;
    return ans;
}

// Function to flatten a multi-level linked list
Node* flattenLinkedList(Node* head) {
    // Check if the list is empty or has no child
    if (head == NULL) {
        return head;
    }

    // Pointer to the current level (head) and the next level (head->next)
    Node* down = head;
    Node* right = head->next;

    // Disconnect the next level (child pointers) to avoid cycles
    down->next = NULL;

    // Recursively flatten the next level
    right = flattenLinkedList(right);

    // Merge the current level and the flattened next level
    Node* ans = merge(down, right);

    // Return the merged result
    return ans;
}

