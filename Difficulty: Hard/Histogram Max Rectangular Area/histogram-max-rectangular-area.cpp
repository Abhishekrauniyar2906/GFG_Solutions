//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find largest rectangular area possible in a given histogram.
    
    
   vector<int> nextsmallerElement(vector<int> &heights){
    stack<int> st;
    st.push(-1);
    vector<int>ans(heights.size());
    for(int i = heights.size() - 1; i >= 0; i--){
        int curr = heights[i];
        while(st.top() != -1 && heights[st.top()] >= curr){
            st.pop();

        }

        ans[i] = st.top();
        st.push(i);
    }
          return ans;
    
   }


 vector<int> prevsmallerElement(vector<int> &heights){
    stack<int> st;
    st.push(-1);
    vector<int>ans(heights.size());
    for(int i = 0; i <= heights.size() - 1; i++){
        int curr = heights[i];
        while(st.top() != -1 && heights[st.top()] >= curr){
            st.pop();

        }

        ans[i] = st.top();
        st.push(i);
    }
          return ans;
    
   }


    int getMaxArea(vector<int>& heights) {
        vector<int> leftans = prevsmallerElement(heights);
          
        vector<int> rightans = nextsmallerElement(heights);

        for(int i = 0; i < heights.size(); i++){
            if(rightans[i] == -1){
                rightans[i] = heights.size();
            }
        }
           vector<int> area(heights.size());
        for(int i = 0; i < heights.size(); i++){
             int width = rightans[i]  - leftans[i] - 1;
             int length = heights[i];
             area[i] = width * length;
        }
         
         int maxi = INT_MIN;

         for(int i = 0; i < area.size(); i++){
           maxi = max(maxi, area[i]);
         }
           return maxi;
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
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends