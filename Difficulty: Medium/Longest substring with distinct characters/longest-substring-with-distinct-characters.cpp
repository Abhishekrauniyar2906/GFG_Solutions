class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int>mp;
        int count = 0;
        int left = 0;
        
        for(int i = 0; i < s.size(); i++){
          mp[s[i]]++;
          
          while(mp[s[i]] > 1){
              mp[s[left]]--;
              left++;
          }
          count = max(count, i - left + 1);
        }
        return count;
    }
};
