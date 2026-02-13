class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        if(k > n) return -1;
       if(k == 1){
           int ans = *max_element(arr.begin(), arr.end());
           return ans;
       }
       int windowSum = 0;
       for(int i = 0; i < k; i++){
           windowSum += arr[i];
       }
       
       int maxSum = windowSum;
        // cout <<"the maxSum is : " << maxSum << endl;
        for(int i = k; i < n; i++){
            windowSum = windowSum - arr[i - k] + arr[i];
            maxSum = max(maxSum, windowSum);
        }
        return maxSum;
    }
};