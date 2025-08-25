

class Solution {
  public:
  void leftBoundary(Node* root, vector<int>&ans){
      if(!root) return;
      
      if(root -> left == NULL && root -> right == NULL) return; 
      
      ans.push_back(root -> data);
      if(root -> left != NULL){
          leftBoundary(root -> left, ans);
      }
      else{
          leftBoundary(root -> right, ans);
      }
  }
  
  void leafBoundary(Node* root, vector<int> &ans){
      if(!root) return;
      
      if(root -> left == NULL && root -> right == NULL){
         ans.push_back(root -> data);  
      }
        leafBoundary(root -> left, ans);
        leafBoundary(root -> right, ans);
      
  }
  
    void rightBoundary(Node* root, vector<int>&ans){
      if(!root) return;
      
      if(root -> left == NULL && root -> right == NULL) return; 
      
      
      if(root -> right != NULL){
          rightBoundary(root -> right, ans);
      }
      else{
          rightBoundary(root -> left, ans);
      }
      ans.push_back(root -> data);
  }
  
    void solve(Node* root, vector<int> &ans){
        if(!root) return;
        ans.push_back(root ->data);
        leftBoundary(root -> left, ans);
        leafBoundary(root -> left, ans);
        leafBoundary(root -> right, ans);
        rightBoundary(root -> right, ans);
        
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
      
      solve(root, ans);
      return ans;
    }
};