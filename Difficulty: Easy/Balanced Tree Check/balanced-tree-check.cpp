//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to build a tree from a string representation
Node* buildTree(string str) {
    if (str.empty() || str[0] == 'N')
        return nullptr;

    vector<string> nodeValues;
    istringstream iss(str);
    for (string s; iss >> s;)
        nodeValues.push_back(s);

    Node* root = new Node(stoi(nodeValues[0]));
    queue<Node*> nodeQueue;
    nodeQueue.push(root);

    size_t i = 1;
    while (!nodeQueue.empty() && i < nodeValues.size()) {
        Node* currentNode = nodeQueue.front();
        nodeQueue.pop();

        string leftValue = nodeValues[i++];
        if (leftValue != "N") {
            currentNode->left = new Node(stoi(leftValue));
            nodeQueue.push(currentNode->left);
        }

        if (i >= nodeValues.size())
            break;

        string rightValue = nodeValues[i++];
        if (rightValue != "N") {
            currentNode->right = new Node(stoi(rightValue));
            nodeQueue.push(currentNode->right);
        }
    }

    return root;
}


// } Driver Code Ends

/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
  
  int height(Node* root){
      if(!root){
          return NULL;
      }
      
      
      int l_h = height(root -> left);
      int r_h = height(root -> right);
      
      return max(l_h, r_h) + 1;
  }
    bool isBalanced(Node* root) {
       
       if(!root){
           return true;
       }
       
       int l_H = height(root -> left);
       int R_H = height(root -> right);
       
       int diff= abs(l_H - R_H) <= 1;
       
       bool leftans = isBalanced(root -> left);
       bool rightans = isBalanced(root -> right);
       
       if(diff && leftans && rightans){
           return true;
       }
       
       return false;
    }
};



//{ Driver Code Starts.

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (testCases--) {
        string treeInput;
        getline(cin, treeInput);

        Node* root = buildTree(treeInput);
        Solution solution;
        bool result = solution.isBalanced(root);

        // Output "true" or "false"
        cout << (result ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends