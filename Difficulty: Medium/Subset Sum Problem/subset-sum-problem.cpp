class Solution {
  public:
    
    bool solve(vector<int> &arr, int sum, vector<vector<int>> &dp){
        for(int i = 0; i <= arr.size() ; i++){
            for(int j = 0; j <= sum; j++){
                if(j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0){
                    dp[i][j] = false;
                }
                
                else if(arr[i - 1] <= j){
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
            
        }
         return dp[arr.size()][sum];
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>>dp(arr.size() + 1, vector<int>(sum + 1));
        
        return solve(arr, sum, dp);
    }
};