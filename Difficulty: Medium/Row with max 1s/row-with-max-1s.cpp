// User function template for C++
class Solution {
  public:
  
  int lower(vector<int> &row){
      int s = 0;
      int e = row.size() - 1;
      
      int ans = -1;
      
      while(s <= e){
          int mid = s + (e - s) / 2;
          
          if(row[mid] >= 1){
              ans = mid;
              e = mid - 1;
          }
          else{
              s = mid + 1;
          }
      }
      return ans;
  }
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        int maxCount = 0;
        int rowIndex = 0;
        
        for(int i = 0; i < n; i++){
            int idx = lower(arr[i]);
            int count = (idx == -1) ? 0 : m - idx;
            
            if(count > maxCount){
                maxCount = count;
                rowIndex = i;
            }
        }
        return rowIndex;
    }
};