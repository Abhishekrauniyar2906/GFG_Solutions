
class Solution {
  public:
    int maxi = INT_MIN;
    
    int solve(Node* root){
            if(!root) return 0;
       
       int left = max(0, solve(root -> left));
       int right = max(0, solve(root -> right));
       
       maxi = max(maxi, root -> data + left + right);
       
       return max(left, right) + root -> data;
    }
    int findMaxSum(Node *root) {
      solve(root);
      return maxi;
    }
    
};