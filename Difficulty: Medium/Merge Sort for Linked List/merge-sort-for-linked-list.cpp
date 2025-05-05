//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends



class Solution {
  public:
    
    Node* merge(Node* left, Node* right){
        
        Node* dummy = new Node(-1);
        Node* ans = dummy;
         
        if(left == 0){
        return right;
        }
        
        if(right == 0){
            return left;
        }
        
        
        while(left && right){
            if(left -> data <= right -> data){
                ans -> next = left;
                ans = left;
                left = left -> next;
            }
            
            else{
                ans -> next = right;
                ans = right;
                right = right -> next;
            }
            
            
        }
        
        if(left){
            ans -> next = left;
        }
        
        if(right){
            ans -> next = right;
        }
        
        Node* mptr = dummy -> next;
        delete dummy;
        
        return mptr;
    }
    Node* middleNode(Node* head){
        if (!head || !head->next) return head;

        Node* slow = head;
        Node* fast = head;
        
        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            }
            
            return slow;
    }
    Node* mergeSort(Node* head) {
      if (!head || !head->next) return head;

      Node* mid = middleNode(head);
      Node* left = head;
      Node* right = mid -> next;
      mid -> next = NULL;
      
      left = mergeSort(left);
      right = mergeSort(right);
      
      return merge(left, right);
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends