class Solution {

  public:
    
    
    int helper(vector<int> &arr, vector<vector<bool>>&dp, int sum){
        int n = arr.size();
        for(int i = 0; i <= arr.size(); i++){
            dp[i][0] = true;
        }
        
        for(int i = 1; i <= arr.size(); i++){
            for(int j = 1; j <= sum; j++){
                if(arr[i - 1] <= j){
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];    
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
                
            }
            
        }
        
        int maxSubsetSum = 0;
        
        for(int j = sum; j >= 0; j--){
            if(dp[n][j] == true){
                maxSubsetSum = j;
                break;
            }
        }
        return maxSubsetSum;
    }
    
    
    int solve(vector<int> &arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        int ans = helper(arr, dp, sum);
        return ans;
        
    }
    int minDifference(vector<int>& arr) {
      long long sum = accumulate(arr.begin(), arr.end(), 0);
      int S = sum / 2;
      int s = solve(arr, S);
      
      return abs(sum - 2 * s);
    }
};
