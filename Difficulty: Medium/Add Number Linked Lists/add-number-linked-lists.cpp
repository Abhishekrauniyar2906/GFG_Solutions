

class Solution {
  public:
  
    Node* rev(Node* head){
        if(!head){
            return 0;
        }
        
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL){
          Node* newNode = curr -> next;
          curr -> next = prev;
          prev = curr;
          curr = newNode;
        }
        return prev;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
       
       if(!head1){
           return head2;
       }
        if(!head2){
            return head1;
        }
        
       head1 = rev(head1);
       head2 = rev(head2);
       
       
        
        int carry = 0;
        Node * temp = NULL;
        Node* tHead = NULL;
        
        while(head1 != NULL || head2 != NULL || carry != 0){
            int sum = 0;
            if(head1 != NULL){
                sum += head1 -> data;
                head1 = head1 -> next;
            }
            
            if(head2 != NULL){
                sum += head2 -> data;
                head2 = head2 -> next;
            }
            
             sum += carry;
            carry = sum / 10;
            int digit = sum % 10;
            Node* newNode = new Node(digit);
            if(temp == NULL){
                temp = newNode;
                tHead = temp;
            }
            else{
                temp -> next = newNode;
                temp = temp -> next;
            }
            
        }
        Node* ans = rev(tHead);
        
        while(ans -> data == 0){
            Node* last = ans;
            ans = ans -> next;
            last -> next = NULL;
            free(last);
        }
        return ans;
    }
};