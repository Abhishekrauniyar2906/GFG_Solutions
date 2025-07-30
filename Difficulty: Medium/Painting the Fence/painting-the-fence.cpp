class Solution {
  public:
  vector<int>dp;
  
    int solve(int n, int k){
        const int MOD =  1e9 + 7;
        if(n == 0) return 0;
        
        if(n == 1) return k;
        
        if(n == 2) return (k + k * (k - 1)) % MOD;
         
        if(dp[n] != -1) return dp[n];
        
        int same = solve(n - 2, k);
        int diff = solve(n - 1, k);
        
        return dp[n] = (same + diff) * (k - 1) % MOD;
    }
    int countWays(int n, int k) {
    
        dp.resize(n + 1, -1);
        return solve(n, k);
    }
};