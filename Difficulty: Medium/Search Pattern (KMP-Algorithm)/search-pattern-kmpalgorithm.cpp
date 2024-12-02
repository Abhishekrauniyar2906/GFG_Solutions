//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<int> ans;
  int n, m;
  void solve(int i, string &pat, string &txt){
      int n = pat.size();
      int m = txt.size();
      if(i >= m){
          return;
      }
      
      auto it = txt.find(pat, i);
      if(it != string::npos){
          ans.push_back(it);
          solve(it + 1, pat, txt);
      }
  }
    vector<int> search(string& pat, string& txt) {
        
        solve(0, pat, txt);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends