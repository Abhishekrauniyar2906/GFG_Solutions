class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& nums, int k) {
    deque<int>dq;
    vector<int>ans;
    
    for(int i = 0; i < k; i++){
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);
    
    int n = nums.size();
    for(int i = k; i < n; i++){
        if(i - dq.front() >= k){
            dq.pop_front();
        }
     
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    
    
    ans.push_back(nums[dq.front()]);
    
    }
    
    return ans;
    }
    
};