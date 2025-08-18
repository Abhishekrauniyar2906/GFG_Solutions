class Solution {
  public:
    int hIndex(vector<int>& citations) {
      int s = 0;
      int e = citations.empty() ? 0 : *max_element(citations.begin(), citations.end());
      int ans = -1;
      
      while(s <= e){
        int mid = s + (e - s) / 2;
        int count = 0;
        for(auto &paper : citations){
            if(paper >= mid){
                count++;
            }
        }
        if(count >= mid){
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