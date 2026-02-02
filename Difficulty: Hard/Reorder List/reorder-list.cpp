
class Solution {
  public:
  
    Node* middle(Node* head){
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            
            
        }
        return slow;
    }
    
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL){
            Node* nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    void merge(Node* A, Node* B){
        while(A && B){
            Node* l1 = A -> next;
            Node* l2 = B -> next;
            
            A -> next = B;
            if(l1 == NULL){
                break;
            }
            B -> next = l1;
            
            A = l1;
            B = l2;
            
        }
    }
    void reorderList(Node* head) {
       
        if(head == 0 || head -> next == 0){
            return;
        }
        
        Node* middleNode = middle(head);
        Node* secondList = reverse(middleNode -> next);
        middleNode -> next = NULL;
        
        merge(head, secondList);
    }
};