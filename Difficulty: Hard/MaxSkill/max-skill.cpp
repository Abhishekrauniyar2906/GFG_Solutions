class Solution {
public:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        // base case: no one left between i and j
        if (i + 1 == j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int maxi = 0;

        for (int k = i + 1; k < j; k++) {
            int skill = arr[i] * arr[k] * arr[j];
            int left = solve(arr, i, k, dp);
            int right = solve(arr, k, j, dp);
            maxi = max(maxi, left + right + skill);
        }

        return dp[i][j] = maxi;
    }

    int maxSkill(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(nums, 0, n - 1, dp);
    }
};
