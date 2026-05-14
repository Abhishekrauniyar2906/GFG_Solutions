

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        unordered_map<int,int>mp;
        Node* temp = head;
        Node* join = temp;
        while(temp != NULL){
            if(mp.find(temp -> data) == mp.end()){
                mp[temp -> data]++;
                join = temp;
                temp = temp -> next;
            }
            else{
                Node* deleteNode = join -> next;
                join -> next = temp -> next;
                temp = temp -> next;
                deleteNode -> next = NULL;
                delete deleteNode;
            }
        }
        return head;
    }
};