
class Solution {
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        set<int> st;
        Node* temp1=head1;
        Node* temp2=head2;
        while(temp1){
            st.insert(temp1->data);
            temp1=temp1->next;
        }
         while(temp2){
            st.insert(temp2->data);
            temp2=temp2->next;
        }
          Node* newHead = nullptr;
         Node* tail = nullptr;

          for (int x : st) {
         Node* newNode = new Node(x);
           if (!newHead) {
            newHead = newNode;
            tail = newHead;
          } else {
            tail->next = newNode;
            tail = tail->next;
           }
       }

    return newHead;
    }
};
