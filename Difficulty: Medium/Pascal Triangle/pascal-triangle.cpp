//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> res;

        for(int i = 0; i < n; i++) {
            vector<int> row(i + 1, 1);  

            for(int j = 1; j < i; j++) {
                row[j] = (res[i - 1][j - 1] + res[i - 1][j]) % MOD;
            }

            res.push_back(row);
        }

        return res[n - 1];  
    }
};




//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends