//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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

            // Create the left child for the current Node
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
    int countPairs(Node* root1, Node* root2, int x) {
        
        int ans = 0;
        stack<Node*>s1,s2;
        
        Node* a = root1;
        Node* b = root2;
        
        while(1){
            while(a){
                s1.push(a);
                a = a -> left;
            }
            
            while(b){
                s2.push(b);
                b = b -> right;
            }
            
            if(s1.empty() || s2.empty()){
                break;
            }
            
            auto atop = s1.top();
            auto btop = s2.top();
            
            int sum = atop -> data + btop -> data;
            
            if(sum == x){
                ++ans;
                s1.pop();
                s2.pop();
                a = atop -> right;
                b = btop -> left;
            }
            else if(sum < x){
                s1.pop();
                a = atop -> right;
            }
            else{
                s2.pop();
                b = btop -> left;
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends