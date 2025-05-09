//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

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

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
       
       Node* insertatTail(Node* &tail, Node* &temp){
           tail -> next = temp;
           tail = temp;
       }
    Node* segregate(Node* head) {
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        
        Node* temp = head;
        
        while(temp != NULL){
             int val = temp -> data;
            if(val == 0){
                insertatTail(zeroTail, temp);
            }
            else if(val == 1){
                insertatTail(oneTail, temp);
            }
            else if(val == 2){
                insertatTail(twoTail, temp);
            }
            temp = temp -> next;
        }
        
        // merge 3 Linked list
        
        if(oneHead -> next != NULL){
            zeroTail -> next = oneHead -> next;
        }
        else{
            zeroTail -> next = twoHead -> next;
        }
        
        oneTail -> next = twoHead -> next;
        twoTail -> next = NULL;
        
        head = zeroHead -> next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
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
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends