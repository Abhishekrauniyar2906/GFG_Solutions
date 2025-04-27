//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends



class Solution {
  public:
  
  int count(Node* root, int l, int h, int counts){
      if(!root) {
          return counts;
      }
      
      
      if(root->data >= l && root->data <= h){
          counts++;  
      }
      
     
      counts = count(root->left, l, h, counts);
      counts = count(root->right, l, h, counts);
      
      return counts;
  }
  
  int getCount(Node *root, int l, int h) {
      return count(root, l, h, 0);
  }
};



//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin >> ws, s);
        int l, r;
        cin >> l >> r;
        Solution ob;
        Node* root = buildTree(s);
        cout << ob.getCount(root, l, r) << endl;
        cout << "~"
             << "\n";
    }
    return 1;
}

// } Driver Code Ends