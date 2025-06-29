class Solution {
  public:
    
    bool isPossible(vector<int> &arr, int mid, int k){
        int studentCount = 1;
        int pagesum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            if(pagesum + arr[i] <= mid){
                pagesum += arr[i];
            }
        
            else{
                studentCount++;
                if(studentCount > k || arr[i] > mid){
                    return false;
                }
                pagesum = 0;
                pagesum += arr[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& arr, int k) {
       int s = 0;
       int e = accumulate(arr.begin(), arr.end(), 0);
       
       int ans = -1;
       while(s <= e){
           int mid = s + (e - s) / 2;
           if(isPossible(arr, mid, k)){
               ans = mid;
               e = mid - 1;
           }
           else{
               s = mid + 1;
           }
       }
       return ans;
    }
};