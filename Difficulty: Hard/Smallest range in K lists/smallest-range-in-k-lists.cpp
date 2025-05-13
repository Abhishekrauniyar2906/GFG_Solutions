//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Info{
    public:
    int data;
    int rowIndex;
    int colIndex;
    
    Info(int data, int row, int col){
        this -> data = data;
        this -> rowIndex = row;
        this -> colIndex = col;
    }
};

struct Compare{
    bool operator()(Info* a, Info* b){
        return a -> data > b -> data;
    }
};

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
     priority_queue<Info*, vector<Info*>, Compare> pq;
      
      int mini = INT_MAX;
      int maxi = INT_MIN;
      for(int i = 0; i < arr.size(); i++){
          int element = arr[i][0];
          Info* temp = new Info(element, i, 0);
          pq.push(temp);
          mini = min(mini,element);
          maxi = max(maxi,element);
      }
      
        int ansStart = mini;
        int ansEnd = maxi;
      
      while(!pq.empty()){
          Info* topNode = pq.top();
          pq.pop();
          
          
          int topRow = topNode -> rowIndex;
          int topCol = topNode -> colIndex;
          
          mini = topNode -> data;
          if((maxi - mini) < (ansEnd - ansStart)){
             ansStart = mini;
             ansEnd = maxi;
          }
          
          
          if(topCol + 1 < arr[topRow].size()){
              int newelement = arr[topRow][topCol + 1];
              maxi = max(maxi, newelement);
              Info* next = new Info(newelement, topRow, topCol + 1);
              pq.push(next);
              
          }
          else{
              break;
          }
      }
       
       vector<int>ans;
       ans.push_back(ansStart);
       ans.push_back(ansEnd);
       return ans;
     
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends