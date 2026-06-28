
class Solution {
  public:
    int minValue(Node* root) {
        // code here
        if(!root) return 0;
        
        if(root -> left != NULL){
            while(root -> left != NULL){
                root = root -> left;
            }
        }
        return root -> data;
    }
};