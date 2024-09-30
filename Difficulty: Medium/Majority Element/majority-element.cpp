//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
         unordered_map<int,int>hash;
         int n = arr.size();
         for(auto a:arr){
             hash[a]++;
         }
          n = n / 2;
          
          for(auto x:hash){
              
              if(x.second > n){
                  return x.first;
              }
          }
          return -1;

    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends