/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

// Function to find the middle of a linked list using slow and fast pointers
Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    // Move slow one step and fast two steps until fast reaches the end
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Return the middle node
    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    // If either list is empty, return the non-empty list
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    // Create a dummy node to simplify the merging process
    Node* ans = new Node(-1);
    Node* temp = ans;

    // Merge the two lists in sorted order
    while (left != nullptr && right != nullptr) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    // Append the remaining nodes from either list
    while (left != nullptr) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != nullptr) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    // Skip the dummy node and return the merged list
    ans = ans->next;
    return ans;
}

// Function to perform merge sort on a linked list
Node* mergeSort(Node* head) {
    // Base case: if the list is empty or has only one node, it is already sorted
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Find the middle of the list
    Node* mid = findMid(head);

    // Split the list into two halves
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;

    // Recursively sort each half
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    Node* result = merge(left, right);

    // Return the sorted list
    return result;
}

