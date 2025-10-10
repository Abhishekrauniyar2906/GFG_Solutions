
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
      vector<int>ans;
      
      if(!root){
          return ans;
      }
      bool LtoRdir = true;
      queue<Node*>q;
      q.push(root);
      
      while(!q.empty()){
          int levelSize = q.size();
          vector<int>level(levelSize);
          for(int i = 0; i < level.size(); i++){
            Node* front = q.front();
            q.pop();
            
            int index = (LtoRdir) ? i : (levelSize - i - 1);
            level[index] = front -> data;
            
            
            
            if(front -> left != NULL){
                q.push(front -> left);
            }
            
            if(front -> right != NULL){
                q.push(front -> right);
            }
            
          }
          
          for(auto val : level){
              ans.push_back(val);
          }
          
          LtoRdir = !LtoRdir;
      }
        return ans;
    }
};