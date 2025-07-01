class Solution {
  public:
  
  int robber(vector<int> &arr, vector<int> &dp, int i){
      int n = arr.size();
      if(i >= arr.size()){
          return 0;
      }
      
      if(dp[i] != -1){
          return dp[i];
      }
      int rob = arr[i] + robber(arr, dp, i + 2);
      int skip = 0 + robber(arr, dp, i + 1);
      return dp[i] = max(rob, skip);
      
  }
    int findMaxSum(vector<int>& arr) {
    vector<int>dp(arr.size() + 1, -1);
    
    int ans = robber(arr, dp, 0);
    return ans;
    }
};