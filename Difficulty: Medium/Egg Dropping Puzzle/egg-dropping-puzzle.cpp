class Solution {
  public:

    vector<vector<int>>dp;
    
    int solve(int e, int f){
        if(f == 0 || f == 1) return f;
        if(e == 1) return f;
        
        if(dp[e][f] != -1) return dp[e][f];
        
        int s = 1, h = f;
        int ans = INT_MAX;
        
        while(s <= h){
            int mid = s + (h - s) / 2;
            
            int Break = solve(e - 1, mid - 1);
            int notBreak = solve(e, f - mid);
            
            int temp =  1 + max(Break, notBreak);
            
            if(Break > notBreak){
                h = mid - 1;
                ans = min(ans, temp);
            }
            else{
                s = mid + 1;
                ans = min(ans, temp);
            }
        }
        return dp[e][f] = ans;
    }
    int eggDrop(int e, int f) {
     dp.resize(e + 1, vector<int>(f + 1, -1));
     return solve(e, f);
    }
};