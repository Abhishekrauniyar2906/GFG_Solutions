class Solution {
  public:
  
bool isPossible(vector<int> &stalls, int k, int mid){
    int cows_count = 1;
    int pos = stalls[0];
    
    for(auto &stall : stalls){
        if(stall - pos >= mid){
            cows_count++;
            pos = stall;
        }
        
        if(cows_count == k) return true;
    }
    return false;
}
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int s = 0;
        int e = stalls[stalls.size() - 1] - stalls[0];
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(isPossible(stalls, k, mid)){
                ans = mid; 
                s = mid + 1;
            }
            else{
              e = mid - 1;
            }
            
        }
        return ans;
    }
};