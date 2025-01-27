//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        stack<int>st;
        int n = mat.size();
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(mat[a][b]){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        //   step 3: check that single person is actually celebirity ?
           int mayBeCelebirity = st.top();
           st.pop();
        //   For the row 
           for(int i = 0; i < n; i++){
               if(mat[mayBeCelebirity][i] != 0){
                   return -1;
               }
           }
           
        //   for the column
           for(int i = 0; i < n; i++){
               if(mat[i][mayBeCelebirity] != 1 && i != mayBeCelebirity){
                   return -1;
               }
           }
         
         return mayBeCelebirity;
         
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends