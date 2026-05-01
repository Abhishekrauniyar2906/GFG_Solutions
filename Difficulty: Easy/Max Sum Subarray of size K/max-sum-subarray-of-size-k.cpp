class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
         
         int sum = 0;
         
         for(int i = 0; i < k; i++){
             sum += arr[i];
         }
         
         int maxSum = sum;
         
         for(int i = k; i < arr.size(); i++){
           sum = sum - arr[i - k] + arr[i];
            maxSum = max(maxSum, sum);
         }
         return maxSum;
    }
};