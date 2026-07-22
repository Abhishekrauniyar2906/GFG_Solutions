class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mp;
        int maxlen = INT_MIN;
        int csum = 0;
        for(int i = 0; i < arr.size(); i++){
            csum += arr[i];
            
            if(csum == k) maxlen = i + 1;
            
            if(mp.find(csum - k) != mp.end()){
                maxlen = max(maxlen, i - mp[csum - k]);
            }
            
            if(mp.find(csum) == mp.end()){
                mp[csum] = i;
            }
        }
        return maxlen == INT_MIN ? 0 : maxlen;
    }
};