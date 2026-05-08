class Solution {
  public:
   
   int atMost(string &s, int k){
        if(k < 0) return 0;
         int left  = 0;
      
        int ans = 0;
        vector<int> freq(26,0);
        int distinct = 0;
        for(int right = 0; right < s.size(); right++){
          
         if(freq[s[right] - 'a'] == 0)
            distinct++;

        freq[s[right] - 'a']++;

        while(distinct > k){

            freq[s[left] - 'a']--;

            if(freq[s[left] - 'a'] == 0){
                distinct--;
            }
            left++;
            
        }
        

        ans += right - left + 1;
        }
        return ans;
   }
    int countSubstr(string& s, int k) {
       
        // code here
      int exactK = atMost(s, k) - atMost(s, k - 1);
      return exactK;
    }
};