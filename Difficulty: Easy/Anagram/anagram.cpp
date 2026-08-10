class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        unordered_map<char,int>m1, m2;
        
        for(auto it : s1){
            m1[it]++;
        }
        
        for(auto it : s2){
            m2[it]++;
        }
        return m1 == m2;
    }
};