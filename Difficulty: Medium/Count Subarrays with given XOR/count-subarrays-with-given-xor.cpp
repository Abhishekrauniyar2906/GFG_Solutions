class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mp;
       
        int ans = 0;
        
        int prefixSum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            prefixSum ^= arr[i];
            
            if(prefixSum == k) ans++;
            if(mp.find(prefixSum ^ k) != mp.end()){
                ans += mp[prefixSum ^ k];
            }
            
            mp[prefixSum]++; 
        }
        return ans;
    }
};