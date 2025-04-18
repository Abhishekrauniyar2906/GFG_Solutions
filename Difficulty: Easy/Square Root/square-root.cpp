//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        
     int s = 0;
  
     int e = n;
   long long  int ans = -1;
     
     while(s <= e){
        long long int mid = s + (e - s) / 2;
         int sqrt = mid * mid;
         
         if(sqrt == n){
            
             return mid;
         }
         
        else if(sqrt < n){
             ans = mid;
             s = mid + 1;
         }
         else{
             e = mid - 1;
         }
     }
     return ans;
     
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends