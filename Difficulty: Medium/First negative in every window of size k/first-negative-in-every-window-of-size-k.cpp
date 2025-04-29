//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
      
      vector<int>ans;
      deque<int>dq;
      
      for(int i = 0; i < k; i++){
          int element = arr[i];
          
          if(element < 0){
              dq.push_back(i);
          }
      }
      
      for(int i = k; i < arr.size(); i++){
          if(dq.empty()){
              ans.push_back(0);
          }
          else{
              ans.push_back(arr[dq.front()]);
          }
        //  removal
        if(i - dq.front() >= k && !dq.empty()){
            dq.pop_front();
        }
         
         if(arr[i] < 0){
             dq.push_back(i);
         }
      }
         if(dq.empty()){
              ans.push_back(0);
          }
          else{
              ans.push_back(arr[dq.front()]);
          }
        
        // 
      
      
      return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.firstNegInt(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends