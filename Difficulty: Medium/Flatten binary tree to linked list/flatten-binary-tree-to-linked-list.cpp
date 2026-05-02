// User function Template for C++

class Solution {
  public:
    void flatten(Node *root) {
        // code here
        Node* curr = root;
        
        while(curr != NULL){
            if(curr -> left != NULL){
            Node* pred = curr -> left;
            
            while(pred -> right != NULL){
                pred = pred -> right;
            }
            
            Node* joinNode = curr -> right;
            
            curr -> right = curr -> left;
           
            curr -> left = NULL;
            pred -> right = joinNode;
            
        }
        curr = curr -> right;
        }
    }
};