class Solution {
  public:
   
    int solve(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp){
      if(curr == nums.size()){
        return 0;
      }

        if(dp[curr][prev + 1] != -1){
          return dp[curr][prev + 1];
        }
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev])
        take = 1 + solve(nums, curr + 1, curr, dp);
         
        int notTake = solve(nums, curr + 1, prev, dp);
        return dp[curr][prev + 1] = max(take, notTake);
        
    }
    int lis(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return solve(nums,0, -1, dp);
    }
};
        
   