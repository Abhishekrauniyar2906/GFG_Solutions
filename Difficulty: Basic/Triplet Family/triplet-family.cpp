//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
  


    int n = arr.size();
    
   
    for (int i = 0; i < n; i++) {
       
        unordered_set<int> s;
        
      
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int needed = arr[i] - arr[j];
                
                
                if (s.find(needed) != s.end()) {
                    
                    return true;
                }
                
              
                s.insert(arr[j]);
            }
        }
    }
    
    return false;



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
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends