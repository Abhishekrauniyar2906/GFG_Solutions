//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        
 
    long ans = 0;
    int sign = 1, i = 0;

    // Skip leading whitespaces
    while (s[i] == ' ') {
        i++;
    }

    // Check for sign
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert valid digits
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';
        ans = ans * 10 + digit;

        // Clamp the result to 32-bit bounds
        if (ans * sign > INT_MAX) return INT_MAX;
        if (ans * sign < INT_MIN) return INT_MIN;

        i++;
    }

    return (int)(sign * ans);


    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends