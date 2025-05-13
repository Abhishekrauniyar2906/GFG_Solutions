//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s, string &t) {
        
        int len1 = s.size();
        int len2 = t.size();
        
        if(len1 < len2){
            return "";
        }
        int ansIndex = -1;
        int ansLen = INT_MAX;
        
        int start = 0;
        int end = 0;
        int count = 0;
         
         unordered_map<char,int>sMap;
         unordered_map<char,int>tMap;
        for(auto ch : t){
            tMap[ch]++;
        }
        
        while(end < s.size()){
            char ch = s[end];
            sMap[ch]++;
          if(sMap[ch] <= tMap[ch]){
                count++;
            }
            
            if(count == len2){
                while(sMap[s[start]] > tMap[s[start]]){
                    sMap[s[start]]--;
                    start++;
                }
            
            
           int windowsize = end - start + 1;
            
            if(windowsize < ansLen){
                ansLen = windowsize;
                ansIndex = start;
            }
            }
            end++;
        }
         if(ansIndex == -1){
            return "";
          }
          
          return s.substr(ansIndex, ansLen);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        string str = obj.smallestWindow(s1, s2);
        if (str.size() == 0) {
            cout << "\"\"" << endl;
        } else {
            cout << str << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends