/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int>ans;
        if(!root) return ans;
        queue<pair<Node*,int>>q;
        q.push({root, 0});
        map<int,int>mp;
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            Node* frontData = front.first;
            int hd = front.second;

            
                mp[hd] = frontData -> data;
            

            if(frontData -> left){
                q.push({frontData -> left, hd - 1});
            }

            if(frontData -> right){
                q.push({frontData -> right, hd + 1});
            }
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};