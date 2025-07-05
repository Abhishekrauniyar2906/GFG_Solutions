class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
      
    vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= arr.size(); i++) {
            dp[i][0] = 1;
        }

        int mod = 1e9 + 10;

        for (int i = 1; i <= arr.size(); i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
                } else {
                    dp[i][j] = dp[i - 1][j] % mod;
                }
            }
        }

        return dp[arr.size()][target];
 
        
    }
};





