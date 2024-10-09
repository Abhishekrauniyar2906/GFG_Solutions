//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
 vector<int>negative;
    vector<int>positive;
      
      for(int i = 0; i < arr.size(); i++){
          if(arr[i] >= 0){
              positive.push_back(arr[i]);
          }
          else{
              negative.push_back(arr[i]);
          }
      }
      
    
         vector<int>merge;
         int n = max(positive.size(),negative.size());
         
            for(int i = 0; i < n; i++){
                if(i < positive.size()){
                    merge.push_back(positive[i]);
                }
                if(i < negative.size()){
                    merge.push_back(negative[i]);
                }
            }
            arr = merge;
            
    } 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends