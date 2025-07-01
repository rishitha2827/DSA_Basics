#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;
        
    Node(int d1, Node* n1) {
        data = d1;
        next = n1;
    }
    Node(int d1) {
        data = d1;
        next = nullptr;
    }
};

Node* convertVec2LL(vector<int> array) {
    Node* head = new Node(array[0]);
    Node* mover = head;
    for (int i = 1; i < array.size(); i++) {
        Node* temp = new Node(array[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traversalOfLL(Node* head) {
    Node* temp = head;
    cout << endl;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool searchEleInLL(Node* head, int ele) {
    Node* temp = head;
    while (temp) {
        if (temp->data == ele) {
            return true; // Return true instead of 1
        }
        temp = temp->next;
    }
    return false; // Return false instead of 0
}

Node* deleteHeadOfLL(Node* head) {
    if (!head) return nullptr;  // In case the list is empty
    Node* temp = head;
    head = head->next;
    delete temp; // Use delete instead of free
    
    return head;
}

Node* deleteOfTailOfLL(Node* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;  // Handle empty or single node list
    
    Node* temp = head;
    while (temp->next && temp->next->next) {
        temp = temp->next;
    }
    
    delete temp->next;  // Use delete instead of free
    temp->next = nullptr; // Now the second last node becomes the last node
    
    return head;
}

Node* deleteKEleOfLL(Node* head, int k) {
    if (head == nullptr || k <= 0) return head;  // Handle empty list and invalid k
    
    Node* temp = head;
    if (k == 1) {
        // Special case for deleting head
        head = head->next;
        delete temp; // Use delete instead of free
        return head;
    }

    Node* prev = nullptr;
    int c = 0;
    while (temp) {
        c++;
        if (c == k) {
            if (prev) {
                prev->next = temp->next;  // Skip the k-th node
            }
            delete temp; // Use delete instead of free
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertAtHead(Node* head, int ele) {
    Node* temp = head;
    Node* q = new Node(ele);
    head = q;
    head->next = temp;
    
    return head;
}

Node* insertAtTail(Node* head, int ele) {
    Node* temp = head;
    Node* q = new Node(ele);
    if (temp == nullptr) return q;  // If the list is empty, return the new node as head
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = q;  // Insert at the end
    return head;
}

Node* insertAtKEle(Node* head, int ele, int k) {
    if (k <= 0) return head;  // Invalid k
    
    Node* temp = head;
    Node* q = new Node(ele);
    
    if (k == 1) {
        q->next = head;  // Insert at the beginning
        return q;
    }

    Node* prev = nullptr;
    int c = 1;  // Start from 1 because we are inserting at the k-th position
    while (temp && c < k) {
        prev = temp;
        temp = temp->next;
        c++;
    }

    if (temp == nullptr && c < k) {
        // k is greater than the length of the list, so return the original list
        delete q;
        return head;
    }

    prev->next = q;
    q->next = temp;  // Insert the new node at position k

    return head;
}

int main() {
    vector<int> vecArray = {12, 45, 76, 2, 67, 20, 7, 58};
    Node* head = convertVec2LL(vecArray);
    
    cout << "Initial Linked List: ";
    traversalOfLL(head);

    cout << "\nSearching for 2: " << searchEleInLL(head, 2);

    // Delete the head
    Node* h1 = deleteHeadOfLL(head);
    cout << "\nAfter deleting head: ";
    traversalOfLL(h1);

    // Delete the tail
    Node* h2 = deleteOfTailOfLL(h1);
    cout << "\nAfter deleting tail: ";
    traversalOfLL(h2);
    
    Node* h3 = deleteKEleOfLL(h2, 4);
    cout << "\nAfter deleting n element: ";
    traversalOfLL(h3);

    Node* h4 = insertAtHead(h3, 90);
    cout << "\nAfter inserting at head: ";
    traversalOfLL(h4);
    
    Node* h5 = insertAtTail(h4, 90);
    cout << "\nAfter inserting at tail: ";
    traversalOfLL(h5);
    
    Node* h6 = insertAtKEle(h5, 90, 5);
    cout << "\nAfter inserting at K-th position: ";
    traversalOfLL(h6);

    return 0;
}
