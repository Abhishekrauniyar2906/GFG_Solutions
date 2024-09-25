//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
       if(s.size() != t.size()){
           return false;
       }
       
       int hash[256] = {0};
       bool isTcharMapped[256] = {0};
       
       for(int i = 0; i < s.size(); i++){
           
           if(hash[s[i]] == 0 && isTcharMapped[t[i]] == 0){
               hash[s[i]] = t[i];
               
               isTcharMapped[t[i]] = true;
           }
           
       }
       for(int i = 0; i < s.size(); i++){
           
           if(hash[s[i]] != t[i] ){
               return false;
           }
       }
       
       return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends