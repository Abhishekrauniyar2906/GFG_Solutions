class Solution {
  public:
    int findFloor(vector<int>& arr, int target) {
        int floor = -1;
        
        int s = 0;
        int e = arr.size() - 1;
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(arr[mid] <= target){
                floor = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return floor;
    }
};
