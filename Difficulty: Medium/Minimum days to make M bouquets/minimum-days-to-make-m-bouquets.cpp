class Solution {
  public:
  
    bool isPossible(vector<int>&arr, int k, int m, int mid){
        int flower = 0;
        
        for(auto num : arr){
            if(num <= mid){
                flower++;
            }
            else{
                flower = 0;
            }
            
            if(flower == k){
                m--;
                flower = 0;
            }
            
            if(m == 0){
                return true;
            }
        }
        return false;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int s = *min_element(arr.begin(), arr.end());
        int e = *max_element(arr.begin(), arr.end());
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(isPossible(arr, k, m, mid)){
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