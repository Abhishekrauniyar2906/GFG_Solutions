class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        bool check = true;
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        
        vector<vector<int>>result;
        result.push_back(arr[0]);
        
        for(int i = 1; i < arr.size(); i++){
            if(!result.empty() && arr[i][0] >= result.back()[1]){
                check = true;
                
            }
            else{
            check = false;
            break;
            }
            result.push_back(arr[i]);
        }
        return check;
    }
};