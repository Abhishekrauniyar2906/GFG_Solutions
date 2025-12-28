class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        
        vector<vector<int>>result;
        result.push_back(intervals[0]);
        
        int count = 0;
        
        for(int i = 1; i < intervals.size(); i++){
            if(!result.empty() && result.back()[1] > intervals[i][0]){
                count++;
                intervals[i].pop_back();
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return count;
        
    }
};
