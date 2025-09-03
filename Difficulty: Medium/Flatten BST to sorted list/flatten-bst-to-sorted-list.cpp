
class Solution {
  public:
  
    
    void inorder(Node* root, Node* &prev){
        if(!root)return;
        
        inorder(root -> left, prev);
        
        
        prev -> right = root;
        root -> left = NULL;
        prev = root;
        
        inorder(root -> right, prev);
    }
    Node *flattenBST(Node *root) {
      if(!root)return NULL;
      
      Node* dummy = new Node(-1);
      Node* prev = dummy;
      
      inorder(root, prev);
      
      prev -> right = NULL;
      Node* newHead = dummy -> right;
      delete dummy;
      
      return newHead;
      
        
    }
};                                                                                  