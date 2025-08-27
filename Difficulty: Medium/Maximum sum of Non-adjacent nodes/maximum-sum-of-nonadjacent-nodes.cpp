
class Solution {
  public:
  
    pair<int,int> solve(Node* root){
        if(!root) return {0, 0};
        
        auto left = solve(root -> left);
        auto right = solve(root -> right);
        // include the sum of exclduing pair sum {inc,exc} of adjecent;
        int a = root -> data + left.second + right.second;
        int b = max(left.first, left.second) + max(right.first, right.second);
        
        return {a,b};
    }
    int getMaxSum(Node *root) {
      auto h = solve(root);
      
      return max(h.first, h.second);
        
    }
};