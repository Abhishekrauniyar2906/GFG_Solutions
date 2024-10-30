//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
     
     unordered_map<int, int> m;
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        // Check if there exists an element `arr[i] - k` that forms a valid pair
        if (m.find(arr[i] - k) != m.end()) {
            count += m[arr[i] - k];
        }
        // Check if there exists an element `arr[i] + k` that forms a valid pair
        if (m.find(arr[i] + k) != m.end()) {
            count += m[arr[i] + k];
        }
        // Update the frequency map for the current element
        m[arr[i]]++;
    }
    return count;
     
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends