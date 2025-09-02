

class Solution {
  public:
   
    int length(Node* &head){
        int count = 0;
        Node* temp = head;
        
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        return count;
    }
    Node* swapKth(Node* head, int k) {
       int len = length(head);
       
       if(k > len) return head;
       
       Node* first = head;
       for(int i = 1; i < k; i++){
           first = first -> next;
       }
          
           
            
            Node* second = head;
           for(int i = 1; i < len - k + 1; i++){
               second = second -> next;
           }
           
           swap(first -> data, second -> data);
       
        return head;
    }
};