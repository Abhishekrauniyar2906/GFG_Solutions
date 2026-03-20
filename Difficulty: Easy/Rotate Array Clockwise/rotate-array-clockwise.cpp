class Solution {
  public:
    void rotateclockwise(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        vector<int>ans;
        
        for(int i = n - k; i < n; i++){
            ans.push_back(nums[i]);
        }
        
        vector<int>temp;
        
        for(int i = 0; i < k; i++){
            temp.push_back(ans[i]);
        }
        
        for(int i = 0; i < n - k; i++){
            temp.push_back(nums[i]);
        }
        
        for(int i = 0; i < temp.size(); i++){
            nums[i] = temp[i];
            }
        
    }
};
