class Solution {
  public:
    int perfectSum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));
     
     for(int i = 0; i <= n; i++){
         dp[i][0] = 1;
     }
       for(int i = 1; i <= arr.size(); i++){
           for(int j = 0; j <= k; j++){
               if(arr[i - 1] <= j)
               dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
               else dp[i][j] = dp[i - 1][j];
           }
           
       }
        return dp[n][k];
    }
};