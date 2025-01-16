//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    stack<char>st;
    int count = 0;
    
    if(s.size() & 1){
        return -1;
    }
    
    for(auto ch : s){
        if(ch == '{')
        st.push(ch);
        else{
        if(!st.empty() && st.top() == '{'){
            st.pop();
        }
        
        else{
            st.push(ch);
        }
    }
    }
    
    
    while(!st.empty()){
        char a = st.top();
        st.pop();
        
         char b = st.top();
        st.pop();
        
        if(a == b){
            count += 1;
        }
        else{
            count += 2;
        }
    }
    
    return count;
    
}









