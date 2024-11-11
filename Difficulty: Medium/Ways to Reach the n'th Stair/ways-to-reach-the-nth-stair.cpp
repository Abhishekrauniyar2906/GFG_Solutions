//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count number of ways to reach the nth stair.
    int countWays(int n) {
      if(n <= 2){
          return n;
          
      }
      int first = 1;
      int second = 2;
      
      for(int i = 3; i <= n; i++){
          int third = first + second;
          first = second;
          second = third;
      }
      return second;
    }
};


//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends