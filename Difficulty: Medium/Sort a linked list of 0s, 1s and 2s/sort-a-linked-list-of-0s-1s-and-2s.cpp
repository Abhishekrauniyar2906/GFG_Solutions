
/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
       
       Node* insertatTail(Node* &tail, Node* &temp){
           tail -> next = temp;
           tail = temp;
       }
    Node* segregate(Node* head) {
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        
        Node* temp = head;
        
        while(temp != NULL){
             int val = temp -> data;
            if(val == 0){
                insertatTail(zeroTail, temp);
            }
            else if(val == 1){
                insertatTail(oneTail, temp);
            }
            else if(val == 2){
                insertatTail(twoTail, temp);
            }
            temp = temp -> next;
        }
        
        // merge 3 Linked list
        
        if(oneHead -> next != NULL){
            zeroTail -> next = oneHead -> next;
        }
        else{
            zeroTail -> next = twoHead -> next;
        }
        
        oneTail -> next = twoHead -> next;
        twoTail -> next = NULL;
        
        head = zeroHead -> next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
    }
};


