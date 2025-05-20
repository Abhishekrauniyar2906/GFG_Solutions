//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends


class Solution {
public:
    
    Node* middleNode(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

   
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    // Step 3: Merge two halves alternately
    void merge(Node* left, Node* right) {
        while (left && right) {
            Node* leftNext = left->next;
            Node* rightNext = right->next;

            left->next = right;
            if (leftNext == nullptr) break;
            right->next = leftNext;

            left = leftNext;
            right = rightNext;
        }
    }

    // Main function to reorder the list
    void reorderList(Node* head) {
        if (head == nullptr || head->next == nullptr) return;

        // Step 1: Find the middle
        Node* mid = middleNode(head);

        // Step 2: Reverse the second half
        Node* second = reverse(mid->next);
        mid->next = nullptr; // Cut the list into two halves

        // Step 3: Merge two halves
        merge(head, second);
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends