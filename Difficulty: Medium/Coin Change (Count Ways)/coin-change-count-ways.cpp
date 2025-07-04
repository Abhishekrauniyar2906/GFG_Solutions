class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        
        vector<int>dp(sum + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < coins.size(); i++){
            int coin = coins[i];
            for(int j = coin; j <= sum; j++){
                dp[j] += dp[j - coin];
            }
        }
        return dp[sum];
    }
};