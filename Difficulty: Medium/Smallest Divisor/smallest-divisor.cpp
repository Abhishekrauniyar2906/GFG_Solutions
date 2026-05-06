class Solution {
  public:
  
    bool isPossible(vector<int>&arr, int mid, int k){
        int sum = 0;
        
        for(auto x : arr){
            sum += ceil((double)x / mid);
        }
        return sum <= k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int s = 1;
        int e = *max_element(arr.begin(), arr.end());
        int ans = -1;
        while(s <= e){
            int mid  = s + (e - s) / 2;
            
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
