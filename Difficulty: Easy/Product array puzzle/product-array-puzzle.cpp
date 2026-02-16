class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size(); 
        
        vector<int>res(n);
        res[0] = 1;
        for(int i = 1; i < arr.size(); i++){
            res[i] = res[i - 1] * arr[i - 1];
        }
        
        
        int right = 1;
        for(int i = n - 1; i >= 0; i--){
            res[i] = res[i] * right;
            right = right * arr[i];
        }
        return res;
    }
};
