//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string>result;

     bool isValid(string &curr){
        
         int count = 0;
        for(auto ch : curr){
            if(ch == '('){
                count++;
            }
            else{
                count--;
                if(count < 0){
                    return false;
                }
            }
           
        }

         return count == 0;
     }
    void solve(string &curr, int n){
        if(curr.length() == 2 * n){
            if(isValid(curr)){
                result.push_back(curr);
                
            }
            return;
        }

            curr.push_back('(');
            solve(curr, n);
            curr.pop_back();
       

            curr.push_back(')');
            solve(curr, n);
            curr.pop_back();
        }
    vector<string> AllParenthesis(int n) 
    {
       string curr = "";
       solve(curr, n);
       return result;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	
cout << "~" << "\n";
}
	return 0; 
} 

// } Driver Code Ends