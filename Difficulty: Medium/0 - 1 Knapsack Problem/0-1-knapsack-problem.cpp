class Solution {
  public:
  
    int solve(int capacity, vector<int> &val, vector<int>& wt,  vector<vector<int>> &dp, int n){
        if(n == 0 || capacity == 0){
            return 0;
        }
        
        if(dp[n][capacity] != -1){
            return dp[n][capacity];
        }
        
        int ans;
        if(wt[n - 1] <= capacity){
            int pick = val[n - 1] + solve(capacity - wt[n - 1], val, wt, dp, n - 1);
            int notpick = solve(capacity, val, wt, dp, n - 1);
            ans = max(pick, notpick);
            
        }
        else{
            ans = solve(capacity, val, wt, dp, n - 1);
        }
        return dp[n][capacity] = ans;
    }
    int knapsack(int capacity, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>>dp(n + 1, vector<int>(capacity + 1, -1));
        
        return solve(capacity, val, wt, dp, n);
        
    }
};