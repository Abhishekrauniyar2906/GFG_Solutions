class Solution {
  public:
    int single(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        
        while(s < e){
            if(s == e){
                return s;
            }
            
            int mid = s + (e - s) / 2;
            
            if(mid % 2 == 1){
                if(arr[mid] == arr[mid - 1]){
                    s = mid + 1;
                }
                else{
                    e = mid;
                }
            }
            
            else{
                if(arr[mid] == arr[mid + 1]){
                    s = mid + 1;
                }
                else{
                    e = mid;
                }
            }
        }
        return  arr[s];
    }
};