//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	bool isPalindrome(string &s, int i, int j){
        
        while(i <= j){
            if(s[i] != s[j]){
                return 0;
            }
            else{
            i++;
            j--;
        }
        }
        return 1;
    }
	
	int isPalindrome(string s)
	{
	     int i = 0;
        int j = s.length() - 1;
        
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
 
                bool ans1 = isPalindrome(s,i+1,j);
                bool ans2 = isPalindrome(s,i,j-1);
            return ans1 || ans2;
            }
        }
//         it means remaining string is a palindrome
        return 1;
	   
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends