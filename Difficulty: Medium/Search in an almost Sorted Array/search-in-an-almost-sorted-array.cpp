// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int n = arr.size();
        int s = 0;
        int e = arr.size() - 1;
    
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(mid - 1 >= 0 && arr[mid - 1] == target){
                return mid - 1;
            }
            
            if(mid + 1 < n && arr[mid + 1] == target){
                return mid + 1;
            }
            
            if(arr[mid] == target){
                return mid;
            }
            
            else if(arr[mid] < target){
              
                s = mid + 2;
            }
            else{
                e = mid - 2;
            }
        }
        return -1;
    }
};