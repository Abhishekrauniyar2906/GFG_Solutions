class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int>mp;
        int longest = INT_MIN;
        
        int left = 0;
        
        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++;
            
            while(mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
                
            }
            if(mp.size() == k){
            longest = max(longest, right - left + 1);    
            }
            
        }
        return longest == INT_MIN ? -1 : longest;
    }
};