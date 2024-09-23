//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       long long N = arr.size();
     long long S1_N = N * (N+1)/2;
     long long S2_N = (N * (N + 1) * (2 * N + 1)) / 6;
       long long  s1 = 0;
     long long s2 = 0;
     for(int i = 0; i < N; i++){
         s1 += arr[i];
         s2 += (long long)arr[i] * (long long)arr[i]; 
     }
     long long val_1 = s1 - S1_N;
     long long val_2 = s2 - S2_N;
     val_2 = val_2 / val_1;
     long long x = (val_2 + val_1) / 2; 
     long long y = x - val_1;
     return {(int)x ,(int)y};

        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends