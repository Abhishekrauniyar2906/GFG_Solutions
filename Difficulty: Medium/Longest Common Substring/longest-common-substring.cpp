class Solution {
  public:
    int longestCommonSubstr(string& s, string& k) {
     int n = s.size();
     int m = k.size();
     
     vector<vector<int>>dp(n + 1, vector<int>(m + 1));
      int res = INT_MIN;
     for(int i = 0; i <= n; i++){
         
             dp[i][0] = 0;
         }
         
           for(int j = 0; j <= m; j++){
             dp[0][j] = 0;
         }
         
         for(int i = 1; i <= n; i++){
             for(int j = 1; j <= m; j++){
                 if(s[i - 1] == k[j - 1]){
                     dp[i][j] = 1 + dp[i - 1][j - 1];
                 }
                 else{
                     dp[i][j] = 0;
                 }
                 
                 res = max(res, dp[i][j]);
             }
         }
         return res;
    }
};