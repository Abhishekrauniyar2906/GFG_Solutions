//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
       stack<int>st;
       
          for(int i = 0; i < s.size(); i++){
            char ch = s[i];
           if(ch == '(' || ch == '-' || ch == '+' || ch == '/' || ch == '*'){
               st.push(ch);
           }
           else{
               if(ch == ')'){
                  int opt_count = 0;
                   while(!st.empty() && st.top() != '('){
                       char temp = st.top();
                       
                       if(temp == '-' || temp == '+' || temp == '/' || temp =='*'){
                           opt_count++;
                       }
                       st.pop();
                   }
                   
                   st.pop();
                   
                   if(opt_count == 0){
                       return 1;
                   }
               }
           }
       }
       return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends