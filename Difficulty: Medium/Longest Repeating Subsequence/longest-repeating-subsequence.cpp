class Solution {
  public:
    int LongestRepeatingSubsequence(string &s) {
       string b = s;
       int n = s.size();
       vector<vector<int>>dp(n + 1, vector<int>(n + 1));
       for(int i = 0; i <= n; i++){
           for(int j = 0; j <=n; j++){
               dp[i][j] = 0;
           }
       }
       
       for(int i = 1; i <= n; i++){
           for(int j = 1; j <= n; j++){
               if(s[i - 1] == b[j - 1] && i != j){
                   dp[i][j] = 1 + dp[i - 1][j - 1];
               }
               else{
                   dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
               }
           }
       }
        return dp[n][n];
    }
};