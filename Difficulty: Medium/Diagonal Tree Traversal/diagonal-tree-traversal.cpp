
class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
          vector<int>ans;
        if(!root) return ans;
      
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            Node* frontNode = q.front();
            q.pop();
            while(frontNode != NULL){
                
                if(frontNode -> left){
                    q.push(frontNode -> left);
                }
                
                ans.push_back(frontNode -> data);
                frontNode = frontNode -> right;
            }
        }
        return ans;
    }
};