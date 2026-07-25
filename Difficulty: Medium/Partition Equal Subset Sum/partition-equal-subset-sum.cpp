class Solution {
  public:
  
   bool solve(vector<int>&arr, int sum){
       int n = arr.size();
       vector<vector<int>>dp(n + 1, vector<int>(sum + 1, 0));
       
       for(int i = 0; i < n; i++){
           dp[i][0] = true;
       }
       
       for(int j = 0; j < sum; j++){
           dp[0][j] = false;
       }
       
       for(int i = 1; i <= n; i++){
           for(int j = 1; j <= sum; j++){
               if(arr[i - 1] <= j){
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
               }
               
              
           else{
               dp[i][j] = dp[i - 1][j];
           }
       }
       }
       return dp[n][sum];
       
   }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if(sum % 2 != 0) return false;
        
        return solve(arr, sum / 2);
    }
};