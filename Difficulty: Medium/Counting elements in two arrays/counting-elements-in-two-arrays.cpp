class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(), b.end());
        int count = 0;
        
        vector<int>ans;
        
        for(int i = 0; i < a.size(); i++){
            count = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
            ans.push_back(count);
        }
        return ans;
        
    }
};