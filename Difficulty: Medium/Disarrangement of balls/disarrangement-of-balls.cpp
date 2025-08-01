// User function Template for C++

class Solution {
  public:
  
  int solve(int n, vector<int> &dp){
       
       if(n == 0) return 1;
       if(n == 1) return 0;
       if(dp[n] != - 1) return dp[n];
        
        int ans = (n - 1) * (solve(n - 1, dp) + solve(n - 2, dp));
        
        return dp[n] = ans;
  }
    int countDer(int n) {
        vector<int>dp(n + 1, -1);
        return solve(n, dp);
    }
};