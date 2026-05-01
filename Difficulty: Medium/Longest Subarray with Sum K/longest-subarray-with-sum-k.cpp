class Solution {
  public:
    int longestSubarray(vector<int>& nums, int k) {
        // code here
        int longest = INT_MIN;
        
        unordered_map<int,int>mp;
        // mp[0] = 1;
        int csum = 0;
        
        int ans = 0;
        
        
        for(int i = 0; i < nums.size(); i++){
            csum += nums[i];
            
            if(csum == k){
              longest = i + 1;
            }
            
            if(mp.find(csum - k) != mp.end()){
               longest = max(longest, i - mp[csum - k]);
            }
            
            if(mp.find(csum) == mp.end()){
              mp[csum] = i;
            }
        }
        return longest == INT_MIN ? 0 : longest;
    }
};