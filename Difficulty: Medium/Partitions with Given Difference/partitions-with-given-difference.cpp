class Solution {
  public:
  
  int solve(vector<int> &arr, int sum){
      int n = arr.size();
      vector<vector<int>>dp(n + 1, vector<int>(sum + 1, 0));
      
      for(int i = 0; i <= n; i++){
          dp[i][0] = 1;
      }
      
      for(int i = 1; i <= n; i++){
          for(int j = 0; j <= sum; j++){
              
              if(arr[i - 1] <= j){
              dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
              }
          
          else{
              dp[i][j] = dp[i - 1][j];
          }
      }
  }
      return dp[n][sum];
  }
    int countPartitions(vector<int>& arr, int d) {
       
        int arrSum = accumulate(arr.begin(), arr.end(), 0);
        
         
         
         if ((arrSum + d) % 2 != 0) return 0;
          int S = (arrSum + d) / 2;

        return solve(arr, S);
    }
};