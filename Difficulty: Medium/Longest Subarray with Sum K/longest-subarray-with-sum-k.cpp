class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int maxLen = 0;
        
        int preFixSum = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i < arr.size(); i++){
            preFixSum += arr[i];
            
            if(preFixSum == k){
                maxLen = i + 1;
            }
            
            if(mp.find(preFixSum - k) != mp.end()){
                maxLen = max(maxLen,  i - mp[preFixSum - k]);
            }
            
            if(mp.find(preFixSum) == mp.end()){
                mp[preFixSum] = i;
            }
        }
        return maxLen;
    }
};