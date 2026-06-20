
class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code a =Here
        Node* a = head1;
        Node* b = head2;
        
        while(a != b){
            if(!a) a = head2;
            else a = a-> next;
            if(!b) b = head1;
            else b = b -> next;
        }
        return a;
    }
};