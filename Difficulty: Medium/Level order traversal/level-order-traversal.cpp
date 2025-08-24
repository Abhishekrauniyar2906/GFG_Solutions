

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        
        vector<vector<int>>Ans;
        
        if(!root) return Ans;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
           int levelsize = q.size();
           vector<int>levelans;
           
           for(int i = 0; i < levelsize; i++){
               Node* front = q.front();
               q.pop();
               
               levelans.push_back(front -> data);
               if(front -> left != NULL){
                   q.push(front -> left);
               }
               
               if(front -> right != NULL){
                   q.push(front -> right);
               }
           }
           Ans.push_back(levelans);
        }
        return Ans;
    }
};