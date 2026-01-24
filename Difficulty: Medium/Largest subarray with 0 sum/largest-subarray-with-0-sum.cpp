class Solution {
  public:
    int maxLength(vector<int>& arr) {
        
           int maxLen = 0;
        
        int preFixSum = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i < arr.size(); i++){
            preFixSum += arr[i];
            
            if(preFixSum == 0){
                maxLen = i + 1;
            }
            
            if(mp.find(preFixSum) != mp.end()){
                maxLen = max(maxLen,  i - mp[preFixSum]);
            }
            
            if(mp.find(preFixSum) == mp.end()){
                mp[preFixSum] = i;
            }
        }
        return maxLen;
    }
};