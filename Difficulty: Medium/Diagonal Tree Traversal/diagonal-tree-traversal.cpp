
        
class Solution {
public:

    void solve(Node* root, map<int, vector<int>>&mp, int h){
      if(!root) return;
       
      mp[h].push_back(root -> data);
      solve(root -> left, mp, h + 1);
      solve(root -> right, mp, h);
    }
    vector<int> diagonal(Node* root) {
        map<int, vector<int>>mp;
        
        vector<int>ans;
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
    