
class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        vector<vector<int>>temp;
        vector<int>ans;
        if(!root)return ans;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
         int size = q.size();
         vector<int>levelans;
         for(int i = 0; i < size; i++){
             Node* front = q.front();
             q.pop();
             levelans.push_back(front -> data);
             
             if(front -> left){
                 q.push(front -> left);
             }
             
             if(front -> right){
                 q.push(front -> right);
             }
         }
         temp.push_back(levelans);
        }
        
        for(auto row : temp){
            for(auto val : row){
                ans.push_back(val);
                // cout << val
            }
        }
        return ans;
    }
};