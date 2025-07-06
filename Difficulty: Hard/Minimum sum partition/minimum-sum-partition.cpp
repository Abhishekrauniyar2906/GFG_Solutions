class Solution {

  public:
  
   int solve(vector<int> &arr, vector<vector<bool>> &dp, int sum){
       int n = arr.size();
       for(int i = 0; i <= n; i++){
           dp[i][0] = true;
       }
       
       for(int i = 1; i <= n; i++){
           for(int j = 1; j <= sum; j++){
               if(arr[i - 1] <= j){
                   dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
               }
               else{
                   dp[i][j] = dp[i - 1][j];
               }
           }
          
           }
            
          int max_Subset_sum = 0;
           for(int j = sum; j >= 0; j--){
               if(dp[n][j]){
                   max_Subset_sum = j;
                   break;
               }
           }
       return max_Subset_sum;
   }
    int minDifference(vector<int>& arr) {
     int S = accumulate(arr.begin(), arr.end(), 0);
      int s = S / 2;
     vector<vector<bool>>dp(arr.size() + 1, vector<bool>(s + 1, 0));
     
     int s1 = solve(arr, dp, s);
     
     //cout << "S = " << S << ", s1 = " << s1 << ", diff = " << abs(S - 2 * s1) << endl;

     return abs(S - 2 * s1);
      
     
     
    }
};
