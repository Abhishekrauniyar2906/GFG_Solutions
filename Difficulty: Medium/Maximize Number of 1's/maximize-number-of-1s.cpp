class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
    
        unordered_map<int,int>mp;
        int maxi = INT_MIN;
        
        int left = 0;
        int longest = INT_MIN;
        for(int right = 0; right < arr.size(); right++){
            if(arr[right] == 1){
                
            
            mp[arr[right]]++;
        }
            maxi = max(maxi, mp[arr[right]]);
            
            while((right - left + 1 - maxi) > k){
                mp[arr[left]]--;
                left++;
            }
            longest = max(longest, right - left + 1);
        }
        return longest == INT_MIN ? 0 : longest;
    }
};
