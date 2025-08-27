
class Solution {
  public:
  
      pair<int,int> height(Node* root){
        if(!root) return (make_pair(0, 0));
        auto lh = height(root -> left);
        auto rh = height(root -> right);
        
        int sum = root -> data;
        if(lh.first == rh.first){
            sum += lh.second > rh.second ? lh.second : rh.second;
        }
        else if(lh.first < rh.first){
            sum += rh.second;
        }
        else{
            sum += lh.second;
        }
         int height = 1 + max(lh.first, rh.first);
        return {height, sum};
    }
    int sumOfLongRootToLeafPath(Node *root) {
         auto h = height(root);
        return h.second;
    }
};
   