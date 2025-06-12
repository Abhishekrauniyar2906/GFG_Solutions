class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
       int i = 0;
       int j = 0;
       
       vector<int>ans;
       
       while(i < a.size() && j < b.size()){
           if(a[i] <= b[j]){
               ans.push_back(a[i++]);
           }
           else{
              ans.push_back(b[j++]);
           }
       }
       
       while(i < a.size()){
           ans.push_back(a[i++]);
       }
       
        while(j < b.size()){
           ans.push_back(b[j++]);
       }
       int n = ans.size();
       if(ans.size() % 2 == 1){
           return ans[n / 2];
       }
       else{
           return (ans[n / 2] + ans[(n / 2) - 1 ] ) / 2.0;
       }
    }
};