
// This function should return head to the DLL
class Solution {
  public:
  
    void inorder(Node* root, Node* &head){
        if(!root) return;
        
       inorder(root -> right, head);
       
       root -> right = head;
       if(head != NULL){
           head -> left = root;
           
        }
        head = root;
        
        inorder(root -> left, head);
    }
    Node* bToDLL(Node* root) {
      if(!root) return NULL;
      
      Node* head = NULL;
      inorder(root, head);
      return head;
        
    }
};