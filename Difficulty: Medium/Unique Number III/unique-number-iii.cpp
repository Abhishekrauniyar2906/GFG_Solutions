//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        map<int,int>mp;
        vector<int>ans;
        for(auto num : arr){
            mp[num]++;
        }
        
        for(auto val : mp){
            if(val.second == 1){
                ans.push_back(val.first);
            }
        }
         int output;
        for(int i = 0; i < ans.size(); i++){
            output = ans[i];
        }
        return output;
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
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends