//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Complete this function
    void permutations(string &S, int i, vector<string> &ans){
        if(i >= S.size()){
            ans.push_back(S);
            return;
        }
        
        for(int j = i; j < S.size(); j++){
            swap(S[i], S[j]);
            permutations(S, i + 1, ans);
            swap(S[i], S[j]);
        }
        
        
    }
    vector<string> permutation(string S) {
        
     vector<string>ans;
    
     permutations(S, 0, ans);

     sort(ans.begin(), ans.end()); 
      return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends