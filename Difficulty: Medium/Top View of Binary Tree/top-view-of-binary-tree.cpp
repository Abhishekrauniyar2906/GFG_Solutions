class Solution {
  public:
    vector<int> topView(Node *root) {
        // code her
        vector<int>ans;
        if(!root) return ans;
        queue<pair<Node*,int>>q;
        q.push({root, 0});
        map<int,int>mp;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            Node* frontData = front.first;
            int hd = front.second;
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = frontData -> data;
            }
            
            if(frontData -> left){
                q.push({frontData -> left, hd - 1});
            }
            
            if(frontData -> right){
                q.push({frontData -> right, hd + 1});
            }
        }
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};