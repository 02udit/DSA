// APPROACH 1------->> optimized  T.C.->O(n) S.C->O(1)

// Definition of a simple Node class for a singly linked list
// class Node {
// public:
//     int data;
//     Node* next;
//     Node* arb; // Pointer to the arbitrary/random node

//     Node(int value) : data(value), next(nullptr), arb(nullptr) {}
// };

// Definition of the Solution class
class Solution {
private:
    // Function to insert a new node at the tail of a linked list
    void insertAtTail(Node* &head, Node* &tail, int data) {
        Node* newNode = new Node(data);
        
        // If the list is empty, set the new node as both head and tail
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            // Otherwise, append the new node to the tail
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    // Function to copy a linked list with arbitrary pointers
    Node* copyList(Node* head) {
        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;
        
        // Copy each node and insert it at the tail of the new list
        Node* temp = head;
        while (temp != nullptr) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // Point original and cloned nodes alternatively in the next pointers
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while (originalNode != nullptr && cloneNode != nullptr) {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        // Adjust arbitrary pointers in the cloned list
        temp = head;
        while (temp != nullptr) {
            if (temp->next != nullptr) {
                // If the original node has an arbitrary pointer, point the cloned node's arbitrary pointer accordingly
                temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
            }
            // Move to the next pair of nodes
            temp = temp->next->next;
        }

        // Separate the original and cloned lists
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != nullptr && cloneNode != nullptr) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != nullptr) {
                cloneNode->next = originalNode->next;
            }

            cloneNode = cloneNode->next;
        }

        // Return the head of the cloned list
        return cloneHead;
    }
};



// APPROACH 1------->>  T.C.->O(n) S.C->O(n)

// Definition of the Solution class
class Solution {
private:
    // Function to insert a new node at the tail of a linked list
    void insertAtTail(Node*& head, Node*& tail, int data) {
        Node* newNode = new Node(data);

        // If the list is empty, set the new node as both head and tail
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            // Otherwise, append the new node to the tail
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    // Function to copy a linked list with arbitrary pointers
    Node* copyList(Node* head) {
        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;
        Node* temp = head;

        // Step 1: Create a copy of the original list and insert nodes at the tail of the new list
        while (temp != nullptr) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // Step 2: Create a mapping from original nodes to their corresponding new nodes
        unordered_map<Node*, Node*> oldToNewNode;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while (originalNode != nullptr && cloneNode != nullptr) {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // Step 3: Adjust the arbitrary pointers in the cloned list using the mapping
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != nullptr) {
            cloneNode->arb = oldToNewNode[originalNode->arb];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // Return the head of the cloned list
        return cloneHead;
    }
};
