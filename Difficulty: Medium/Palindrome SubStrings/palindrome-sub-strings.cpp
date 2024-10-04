//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
     int count = 0;
      void expand(char s[],int i,int j,int n ){
          
    //int count = 0;
    while(i >= 0 && j < n && s[i] == s[j]){
        if(i != j)
        count++;
        i--;
        j++;
    }
    
}
   int CountPS(char s[], int n) {
       
        for(int i = 0; i < n; i++){
           expand(s,i,i,n);
           expand(s,i,i+1,n);
            
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        char S[N + 1];
        cin >> S;
        Solution ob;
        cout << ob.CountPS(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends