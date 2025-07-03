#include<bits/stdc++.h>
using namespace std;

// Node class represents a doubly linked list node
class Node {
    public:
        int data;   // Stores the data of the node
        Node* back; // Pointer to the previous node
        Node* next; // Pointer to the next node
        
        // Constructor to initialize a node with given data and null previous and next pointers
        Node(int d1, Node* b1, Node* n1) {
            data = d1;
            b1 = nullptr;
            n1 = nullptr;
        }

        // Constructor to initialize a node with data, and both back and next pointers as null
        Node(int d1) {
            data = d1;
            back = nullptr;
            next = nullptr;
        }
};

// Function to convert a vector of integers into a doubly linked list
Node* convertArr2DLL(vector<int> a) {
    Node* head = new Node(a[0]); // Create the head node with the first element
    Node* prev = head;           // Previous node to track the last inserted node

    // Loop through the rest of the array and build the linked list
    for (int i = 1; i < a.size(); i++) {
        Node* temp = new Node(a[i], prev, nullptr); // Create new node
        prev->next = temp; // Link the previous node to the current one
        prev = temp;        // Move prev to the current node
    }
    return head; // Return the head of the doubly linked list
}

// Function to print the doubly linked list
void print(Node* head) {
    while (head) {
        cout << head->data << "->"; // Print current node's data
        head = head->next;          // Move to the next node
    }
    cout << "NULL" << endl; // End of the list
}

// Function to delete the node at the front of the doubly linked list
Node* deleteAtFront(Node* head) {
    Node* prev = head;  // Store the current head node
    head = head->next;   // Move the head pointer to the next node
    prev->next = nullptr; // Disconnect the old head node
    if (head) {
        head->back = nullptr; // Set the back pointer of the new head to null
    }
    free(prev); // Free memory of the old head node
    return head; // Return the new head
}

// Function to delete the node at the back of the doubly linked list
Node* deleteAtBack(Node* head) {
    if (head == NULL || head->next == NULL) return NULL; // Empty list or single node
    Node* prev = head;
    
    // Traverse to the second last node
    while (prev->next->next) {
        prev = prev->next;
    }

    Node* del = prev->next;  // The last node to be deleted
    del->back = nullptr;     // Set its back pointer to null
    prev->next = nullptr;    // Set the second last node's next pointer to null
    free(del);               // Free the last node's memory
    
    return head; // Return the modified head
}

// Function to delete the node at the k-th position in the doubly linked list
Node* deleteAtKPos(Node* head, int k) {
    if (head == NULL || head->next == NULL) return NULL; // Empty list or single node
    Node* prev = head;
    int c = 0;  // Counter to track the current node's position
    Node* before = NULL; // To keep track of the node before the current node
    
    // Traverse through the list to find the k-th node
    while (prev) {
        c++;
        if (c == k) {
            Node* qwe = prev->next; // Node after the current one
            before->next = qwe;     // Connect the previous node to the next node
            if (qwe) {
                qwe->back = before; // Set the back pointer of the next node
            }
            prev->back = NULL;      // Disconnect the current node from its previous node
            prev->next = NULL;      // Disconnect the current node from its next node
            free(prev);             // Free memory of the current node
        }
        before = prev;    // Move the 'before' pointer to the current node
        prev = prev->next; // Move to the next node
    }
    return head; // Return the modified head
}

// Function to insert a new node at the head of the list
Node* insertAtHead(Node* head, int ele) {
    Node* temp = head;
    Node* eles = new Node(ele); // Create a new node with the given data
    head = eles;                // Make the new node the head of the list
    head->next = temp;          // Link the new head to the old head
    if (temp) {
        temp->back = head;      // Set the old head's back pointer to the new head
    }
    
    return head; // Return the new head
}

// Function to insert a new node at the tail of the list
Node* insertAtTail(Node* head, int ele) {
    Node* temp = head;
    Node* eles = new Node(ele); // Create a new node with the given data
    
    // Traverse to the last node
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = eles;  // Link the last node to the new node
    eles->back = temp;  // Set the back pointer of the new node
    
    return head; // Return the original head (no change here)
}

// Function to insert a new node at the k-th position in the list
Node* insertAtKEle(Node* head, int k, int ele) {
    if (head == NULL) return NULL; // If the list is empty, return NULL

    Node* temp = head;
    Node* eles = new Node(ele); // Create a new node with the given data

    // Insert at the head (if k == 1)
    if (k == 1) {
        eles->next = head;
        head->back = eles;
        return eles; // Return the new head
    }
    
    int c = 1;
    Node* prev = NULL;
    while (temp) {
        if (c == k) {  // Found the k-th position
            prev->next = eles;  // Link the previous node to the new node
            eles->back = prev;  // Set the back pointer of the new node
            Node* qwe = temp;   // Store the node after the k-th position
            eles->next = qwe;   // Link the new node to the next node
            if (qwe) {
                qwe->back = eles; // Set the back pointer of the next node
            }
            break; // Exit the loop after inserting the node
        }
        prev = temp;      // Move the prev pointer to the current node
        temp = temp->next; // Move to the next node
        c++;
    }

    if (c < k) return head; // If k is greater than the length, return the original head

    return head; // Return the modified head
}

// Main function to test the implementation
int main() {
    vector<int> arr = {2, 4, 6, 3, 5, 68, 45, 3, 456}; // Initialize an array of integers
    Node* h1 = convertArr2DLL(arr);  // Convert array to doubly linked list
    print(h1);                       // Print the list

    Node* h2 = deleteAtFront(h1);    // Delete node at the front
    print(h2);                       // Print the list after deletion
    
    Node* h3 = deleteAtBack(h2);     // Delete node at the back
    print(h3);                       // Print the list after deletion

    Node* h4 = deleteAtKPos(h3, 3);  // Delete node at position 3
    print(h4);                       // Print the list after deletion

    Node* h5 = insertAtHead(h4, 12); // Insert node at the head
    print(h5);                       // Print the list after insertion

    Node* h6 = insertAtTail(h5, 12); // Insert node at the tail
    print(h6);                       // Print the list after insertion

    Node* h7 = insertAtKEle(h6, 4, 12); // Insert node at position 4
    print(h7);                           // Print the list after insertion

    return 0;
}
