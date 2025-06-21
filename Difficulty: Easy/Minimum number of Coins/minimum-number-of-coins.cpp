// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int n) {
       
       vector<int>currency={1,2,5,10,20,50,100,200,500,2000};
      
       vector<int>ans;
       int i = currency.size() - 1;
       while(n != 0){
           while(n >= currency[i]){
               ans.push_back(currency[i]);
               n -= currency[i];
           }
           i--;
       }
        return ans;        
    }
};