class Solution {
  public:
  
    bool isPossible(vector<int>& arr, int k, int mid){
        int sum = 0;
        
        for(int i = 0; i < arr.size(); i++){
             sum += ceil((double)arr[i] / mid);

        }
        
        return sum <= k;
      
    }
    int smallestDivisor(vector<int>& arr, int k) {
      
      
       int s = 1;
       int e = *max_element(arr.begin(), arr.end());
       
       int ans = -1;
       
       while(s <= e){
           int mid = s + (e - s) / 2;
           if(isPossible(arr, k, mid)){
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
