class Solution {
  public:
    vector<int> getAlternates(vector<int> &arr) {
        int i = 0;
        vector<int>ans;
       while(i < arr.size()){
           if(i % 2 == 0){
               ans.push_back(arr[i]);
               
           }
           i++;
       }
       return ans;
    }
};