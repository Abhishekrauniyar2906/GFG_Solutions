

class Solution {
  public:
    
    void inorder1(Node* &root1, vector<int> &ans1){
        if(!root1)return;
        
        inorder1(root1 -> left, ans1);
        ans1.push_back(root1 -> data);
        inorder1(root1 -> right, ans1);
    }
    
    void inorder2(Node* root2, vector<int> &ans2){
        if(!root2)return;
        inorder2(root2 -> right, ans2);
        ans2.push_back(root2 -> data);
        inorder2(root2 -> left, ans2);
    }
    int countPairs(Node* root1, Node* root2, int x) {
        vector<int>ans1;
        vector<int>ans2;
        inorder1(root1, ans1);
        inorder2(root2, ans2);
         
         int i = 0;
         int j = 0;
         int count = 0;
         
         while(i < ans1.size() && j < ans2.size()){
             int sum = ans1[i] + ans2[j];
             if(sum == x){
              i++;
              j++;
              count++;
             }
         else if(sum < x){
            i++;
         }
         else{
             j++;
         }
         }
         return count;
    }
};