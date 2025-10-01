class Solution {
  public:
  
    void solve(vector<int> &arr, int index, set<vector<int>> &Unique){
        if(index >= arr.size()){
            Unique.insert(arr);
            return;
        }
        
        for(int j = index; j < arr.size(); j++){
            swap(arr[index], arr[j]);
            solve(arr, index + 1, Unique);
            swap(arr[index], arr[j]);
            }
        
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        set<vector<int>>Unique;
        vector<int>output;
        
        solve(arr, 0, Unique);
        
        vector<vector<int>>ans(Unique.begin(), Unique.end());
        
        return ans;
        
    }
};