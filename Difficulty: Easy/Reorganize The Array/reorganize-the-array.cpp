//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
      int n = arr.size();
      vector<int>result = arr;
  for (int i = 0; i < n; i++) {
        while (result[i] != -1 && result[i] != i) {
            swap(result[i], result[result[i]]);
        }
    }
         
    
    for (int i = 0; i < n; i++) {
        if (result[i] != i) {
            result[i] = -1;
        }
    }
    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends