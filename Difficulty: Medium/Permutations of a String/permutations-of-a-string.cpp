//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  void permutation(string &s, int i, set<string> &unique){
      if(i >= s.length()){
         unique.insert(s);
          return;
      }
      for(int j = i; j < s.length(); j++){
          swap(s[i], s[j]);
          permutation(s, i + 1, unique);
              swap(s[i], s[j]);
      }
  }
    vector<string> findPermutation(string &s) {
        set<string>unique;
        permutation(s, 0, unique);
        
        vector<string>ans(unique.begin(), unique.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends