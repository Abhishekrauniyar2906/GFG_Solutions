
class Solution {
  public:
   
   vector<int> solve(Node* root, vector<int>&ans){
              
       vector<int>result;
       if(root == NULL)return result;
       map<int,int>levelDistance;
       queue<pair<Node*, int>>q;
       q.push(make_pair(root, 0));

      
       while(!q.empty()){
          pair<Node*,int> temp = q.front();
           q.pop();
           
           Node* frontNode = temp.first;
           int topViewAns = temp.second;
           
           if(levelDistance.find(topViewAns) == levelDistance.end()){
               levelDistance[topViewAns] = frontNode -> data;
           }
           
           if(frontNode -> left != NULL){
               q.push(make_pair(frontNode -> left, topViewAns - 1));
           }
           
           if(frontNode -> right != NULL){
               q.push(make_pair(frontNode -> right, topViewAns + 1));
           }
           
       }
       
       for(auto it : levelDistance){
          result.push_back(it.second);
       }
       return result;
   }
    vector<int> topView(Node *root) {
     vector<int>ans;
     return solve(root, ans);
     
    }
};