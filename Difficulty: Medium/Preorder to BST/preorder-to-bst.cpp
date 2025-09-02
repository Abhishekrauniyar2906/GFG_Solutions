// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/


class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    
    Node* solve(int pre[], int size, long long mini, long long maxi, int &i){
        
        if(i >= size) return NULL;
        
        Node* root = NULL;
        
        if(pre[i] > mini && pre[i] < maxi){
            root =  newNode(pre[i++]);
            
            root -> left = solve(pre, size, mini, root -> data, i);
            root -> right = solve(pre, size, root -> data, maxi,i);
        }
        return root;
    }
    Node* Bst(int pre[], int size) {
       int i = 0;
        return solve(pre, size, LLONG_MIN, LLONG_MAX, i);
        
        
    }
};