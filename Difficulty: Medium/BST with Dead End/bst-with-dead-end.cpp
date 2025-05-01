//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends

class Solution {
  public:
  
  void checkBst(Node* root, bool &ans, unordered_map<int, bool> &visited){
      if (!root) return;

      visited[root->data] = true;

      if (!root->left && !root->right) {
          int xplusone = root->data + 1;
          int xminusone = (root->data == 1) ? root->data : root->data - 1;

    
          if (visited.find(xplusone) != visited.end() && visited.find(xminusone) != visited.end()) {
              ans = true;
              return;
          }
      }

      checkBst(root->left, ans, visited);
      checkBst(root->right, ans, visited);
  }

  bool isDeadEnd(Node *root) {
      bool ans = false;
      unordered_map<int, bool> visited;

      visited[0] = true; 
      checkBst(root, ans, visited);

      return ans;
  }
};


//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    
cout << "~" << "\n";
}
}


// } Driver Code Ends