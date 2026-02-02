class Solution {
  public:
  
  struct Compare{
  bool operator()(string a, string b){
      return a + b > b + a;
  }
  };
    string findLargest(vector<int> &arr) {
        vector<string>ans;
        
        for(auto ch : arr){
            ans.push_back(to_string(ch));
        }
        
        sort(ans.begin(), ans.end(), Compare());
        
        if(ans[0] == "0"){
            return "0";
        }
        string res = "";
        for(auto it : ans){
            res += it;
        }
        return res;
    }
};