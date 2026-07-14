

class Solution {
  public:
  
  int maxi = INT_MIN;
  
  int solve(Node* root){
      if(!root) return NULL;
        int leftans = max(0, solve(root -> left));
        int rightans = max(0, solve(root -> right));
        
        maxi = max(maxi, leftans + rightans + root -> data);
        
        return max(leftans, rightans) + root -> data;
  }
    int findMaxSum(Node *root) {
        
        solve(root);
        // code here
       return maxi;
    }
};