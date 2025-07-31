class Solution {
  public:
    
    vector<unsigned int> dp;
    int solve(vector<int>& arr, int key){
        if(key < 0) return 0;
        dp[0] = 1;
        
        for(int i = 1; i <= key; i++){
            for(int j = 0; j < arr.size(); j++){
                if(i - arr[j] >= 0)
                dp[i] += dp[i - arr[j]];
            }
        }
        return dp[key];
    }
    int combinationSum4(vector<int>& arr, int key) {
       dp.resize(key + 1, 0);
       return solve(arr, key);
    }
};