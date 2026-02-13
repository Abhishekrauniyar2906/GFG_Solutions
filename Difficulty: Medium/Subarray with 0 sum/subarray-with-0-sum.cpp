class Solution {
  public:
    
    bool subArrayExists(vector<int>& arr) {
       
        unordered_map<int,bool>mp;
        int sum = 0;
        for(int right = 0; right < arr.size(); right++){
          sum += arr[right];
          
          if(sum == 0)return true;
          
          if(mp.count(sum)){
              return true;
          }
          mp[sum] = 1;
        }
        return false;
    }
};