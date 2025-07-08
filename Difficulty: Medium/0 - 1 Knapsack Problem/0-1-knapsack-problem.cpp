class Solution {
  public:
   
   int solve(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp){
      
      for(int i = 1; i <= n; i++){
          for(int w = 1; w <= W; w++){
              if(wt[i - 1] <= w){
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);  
              }
              else{
                  dp[i][w] = dp[i - 1][w];
              }
          }
      }
       return dp[n][W];
       
   }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>>dp(n + 1, vector<int>(W + 1, 0));
        
        int ans = solve(W, val, wt, n, dp);
        
        return ans;
        
    }
};