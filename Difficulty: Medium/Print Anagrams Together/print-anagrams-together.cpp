//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
     std::array<int,256>hash(string s){
        std::array<int,256>hash = {0};
        
        for(int i = 0; i < s.size(); i++){
               hash[s[i]]++;
        }
        return hash;
    }
    vector<vector<string> > Anagrams(vector<string>& strs) {
    
 

        map<std::array<int,256>,vector<string>>mp;
        
        for(auto str:strs){
              
            
            mp[hash(str)].push_back(str);
        }
        
        vector<vector<string>>ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it -> second);
        }
        return ans;
  
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends