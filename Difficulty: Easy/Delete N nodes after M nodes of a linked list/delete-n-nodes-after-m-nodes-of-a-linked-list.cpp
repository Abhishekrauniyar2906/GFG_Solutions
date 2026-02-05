/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        if(!head || m == 0)return head;
        Node* curr = head;
        
        while(curr != NULL){
        for(int i = 1; i < m && curr != NULL; i++){
            curr = curr -> next;
        }
        
        if(curr == NULL){
            break;
        }
        
        Node* temp = curr -> next;
        
        for(int i = 0; i < n && temp != NULL; i++){
            Node* del = temp;
            temp = temp -> next;
            delete del;
        }
        
        curr -> next = temp;
        curr = temp;
        
        }
        return head;
        
    }
};