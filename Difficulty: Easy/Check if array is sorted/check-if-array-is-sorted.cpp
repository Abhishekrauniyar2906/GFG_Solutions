//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool sorted(vector<int> &arr, int n, int i){
      if(i == n - 1){
          return true;
      }
      
      if(arr[i] > arr[i + 1]){
          return false;
      }
      sorted(arr, n, i + 1);
  }
    bool arraySortedOrNot(vector<int>& arr) {
       int n = arr.size();
       int i = 0;
       return sorted(arr, n, i);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(nums);
        cout << (ans ? "true" : "false") << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends