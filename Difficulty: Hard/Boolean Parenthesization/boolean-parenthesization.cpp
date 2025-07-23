// User function Template for C++
class Solution {
  public:
    
    int solve(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>>&dp){
        if(i > j) return 0;
        
        if(i == j){
            if(isTrue){
                return s[i] == 'T';
            }
            else{
                return s[i] == 'F';
            }
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        int ways = 0;
        for(int k = i + 1; k <= j - 1; k += 2){
            
            int LT = solve(s, i, k - 1, true, dp);
            int LF = solve(s, i, k - 1 , false, dp);
            int RT = solve(s, k + 1, j, true, dp);
            int RF = solve(s, k + 1, j, false, dp);
            
            if(s[k] == '&'){
                if(isTrue){
                    ways += LT * RT;
                }
                else{
                    ways += LT * RF + LF * RT + LF * RF;
                }
            }
            
            if(s[k] == '|'){
                if(isTrue){
                    ways += LT * RT + RF * LT + LF * RT;
                }
                else{
                    ways += LF * RF;
                }
            }
            
            if(s[k] == '^'){
                if(isTrue){
                    ways += LT * RF + LF * RT;
                }
                else{
                    ways += LF * RF + LT * RT;
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int countWays(string &s) {
        int n = s.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
         
         return solve(s, 0, n - 1, true, dp);
    }
};