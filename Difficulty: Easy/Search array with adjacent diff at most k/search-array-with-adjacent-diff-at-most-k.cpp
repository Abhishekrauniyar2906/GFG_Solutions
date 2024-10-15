//{ Driver Code Starts
// C++ program to search an element in an array
// where difference between all elements is 1
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.

class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
      int n = arr.size();  // Get the size of the array
    int i = 0;  // Initialize the index

    // Traverse the array
    while (i < n) {
        // If we find the key, return the current index
        if (arr[i] == x) {
            return i;
        }

        // Jump to the next index based on the difference between the current element and x
        // Since the difference between adjacent elements is at most k, we can skip over unnecessary indices
        i += max(1, abs(arr[i] - x) / k);
    }

    // If the key is not found, return -1
    return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int k, x;
        cin >> k >> x;
        Solution sol;
        int ans = sol.findStepKeyIndex(arr, k, x);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends