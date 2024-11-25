//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    
    int maxProduct(vector<int> &arr) {
        if (arr.empty()) return 0;  // Handle edge case where the array is empty
        
        int maxProd = arr[0], minProd = arr[0], result = arr[0];
        
       
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < 0) {
                // Swap maxProd and minProd when we encounter a negative number
                swap(maxProd, minProd);
            }
            
            // Update maxProd and minProd for the current element
            maxProd = max(arr[i], maxProd * arr[i]);
            minProd = min(arr[i], minProd * arr[i]);
            
            // Update result with the maximum of result and maxProd
            result = max(result, maxProd);
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
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends