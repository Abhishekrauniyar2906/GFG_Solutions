class Solution {
  public:
    
    int nodeCount(Node* root){
        if(!root) return 0;
        
        int l = nodeCount(root -> left);
        int r = nodeCount(root -> right);
        
        return l + r + 1;
    }
    
    bool isValidCBT(Node* root, int i, int n){
        if(!root) return true;
        
        if(i > n) return false;
        
        return isValidCBT(root -> left, 2 * i, n) && isValidCBT(root -> right, 2 * i + 1, n);
    }
    bool isCompleteBT(Node* root) {
        int n = nodeCount(root);
        int i = 1;
        
        return isValidCBT(root, i, n);
        
    }
};