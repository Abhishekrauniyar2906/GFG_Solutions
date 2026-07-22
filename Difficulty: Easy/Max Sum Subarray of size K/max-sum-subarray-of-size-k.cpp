class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int windowsum = 0;
        for(int i = 0; i < k; i++){
            windowsum += arr[i];
        }
        int maxisum = windowsum;
        
        for(int i = k; i < arr.size(); i++){
            windowsum = windowsum - arr[i - k] + arr[i];
            maxisum = max(maxisum, windowsum);
        }
        return maxisum;
    }
};