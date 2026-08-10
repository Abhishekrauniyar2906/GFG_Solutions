/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
  
   void solve(Node* root,  map<int,vector<int>>&mp, int hd){
       if(!root) return;
       
       mp[hd].push_back(root -> data);
       solve(root-> left, mp, hd+ 1);
       solve(root -> right, mp, hd);
   }
    vector<int> diagonal(Node *root) {
        vector<int>ans;
        // code here
        if(!root) return ans;
        map<int,vector<int>>mp;
        
        solve(root, mp, 0);
       
        for(auto it : mp){
           vector<int>temp = it.second;
           
           for(auto i : temp){
               ans.push_back(i);
               
           }
            
        }
        return ans;
    }
};