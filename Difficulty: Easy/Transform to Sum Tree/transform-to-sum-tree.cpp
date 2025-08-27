
class Solution {
  public:
  
  int solve(Node* root){
      if(!root)return 0;
      
      int temp = root -> data;
      
      int leftSum = solve(root -> left);
      int rightSum = solve(root -> right);
      
     root -> data = leftSum + rightSum;
     return root -> data + temp;
  }  
    
    void toSumTree(Node *root) {
        if(!root)return; 
        
        solve(root);
    }
};