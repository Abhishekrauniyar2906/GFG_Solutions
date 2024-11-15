//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
    priority_queue<int> pq;
    for(int i=0;i<arr.size();i++)
    {
        pq.push(arr[i]);
    }
    
    int maxi=pq.top();
    pq.pop();
    while(!pq.empty() && pq.top()==maxi){
        pq.pop();
    }
    
    if(pq.empty()){
        return -1;
    }
    return pq.top();
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends