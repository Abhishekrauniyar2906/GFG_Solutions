//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   std::array<int,256>hash(string s){
        std::array<int,256>hash = {0};
        
        for(int i = 0; i < s.size(); i++){
               hash[s[i]]++;
        }
        return hash;
    }
    vector<vector<string> > anagrams(vector<string>& strs) {
    
 

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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends