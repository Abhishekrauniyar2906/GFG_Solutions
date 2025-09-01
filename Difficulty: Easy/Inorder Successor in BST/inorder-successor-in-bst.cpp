

class Solution {
  public:
   
    int inOrderSuccessor(Node *root, Node *x) {
    
    int succ = -1;
    Node* curr = root;
    
    while(curr){
        if(curr -> data > x -> data){
            succ = curr -> data;
            curr = curr -> left;
        }
        else{
            curr = curr -> right;
        }
    }
        return succ;
    }
};