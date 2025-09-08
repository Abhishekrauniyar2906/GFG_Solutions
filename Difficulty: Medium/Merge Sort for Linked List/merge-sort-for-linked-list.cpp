
class Solution {
  public:
   
    Node* merge(Node* left, Node* right){
      
      Node* dummy = new Node(-1);
      Node* ans = dummy;
      if(left == 0){
          return right;
      }
      
      if(right == 0) {
          return left;
      }
      
      while(left && right){
        
        if(left -> data <= right -> data){
            ans -> next = left;
            ans = left;
            left = left -> next;
        }
        else{
            ans -> next = right;
            ans = right;
            right = right -> next;
        }
        }
        
        if(left) {
            ans -> next = left;
        }
        
        if(right){
            ans -> next = right;
        }
        
        Node* temp = dummy -> next;
        delete dummy;
        
        return temp;
        
    }
    Node* middleNode(Node* head){
        if(!head || !head -> next)return head;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast -> next != NULL && fast -> next -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    Node* mergeSort(Node* head) {
     if(!head || !head -> next)return head;
     
     Node* mid = middleNode(head);
     Node* left = head;
     Node* right = mid -> next;
     mid -> next = NULL;
     
     left = mergeSort(left);
     right = mergeSort(right);
     
     return merge(left, right);
    }
};