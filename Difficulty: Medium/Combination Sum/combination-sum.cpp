//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    void combination_Sum(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &v, int index) {
        if (target < 0) return;  // If target becomes negative, stop further recursion
        if (target == 0) {  
            ans.push_back(v);  // Store the valid combination
            return;            // Return to prevent unnecessary recursion
        }

        for (int i = index; i < candidates.size(); i++) {
            v.push_back(candidates[i]);
            combination_Sum(candidates, target - candidates[i], ans, v, i); // Allow same element reuse
            v.pop_back(); // Backtrack to explore other combinations
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        combination_Sum(candidates, target, ans, v, 0);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        vector<vector<int>> ans = ob.combinationSum(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends