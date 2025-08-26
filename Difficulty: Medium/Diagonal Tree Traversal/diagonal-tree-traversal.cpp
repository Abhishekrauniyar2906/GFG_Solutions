
class Solution {
  public:
  
    void solve(Node* root, int D, map<int, vector<int>> &mp){
        if(!root)return;
        
        mp[D].push_back(root -> data);
        
        solve(root -> left, D + 1, mp);
        solve(root -> right, D, mp);
    }
    vector<int> diagonal(Node *root) {
        // code here
        vector<int>ans;
        
        map<int, vector<int>> mp;
        
        solve(root, 0, mp);
        
        for(auto i : mp){
            for(auto value : i.second)
            ans.push_back(value);
        }
        
        return ans;
        
        
        
    }
};