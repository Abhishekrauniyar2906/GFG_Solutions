class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mp;
        mp[0] = 1;
        int csum = 0;
        int oddCount = 0;
        
        int ans = 0;
        
        for(int i = 0; i < arr.size(); i++){
            csum += arr[i];
            if(arr[i] % 2 != 0){
                oddCount++;
            }
            
            if(mp.find(oddCount - k) != mp.end()){
                ans += mp[oddCount - k];
            }
        mp[oddCount]++;
        }
        return ans;
    }
};