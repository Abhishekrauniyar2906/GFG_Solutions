//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


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


class Compare{
    
    public:
    
    bool operator()(Info* a, Info* b){
        return a -> data > b -> data;
    }
};

class Solution {
  public:
  
   void mergeKsortedArrays(vector<vector<int>> arr, int K, vector<int> &ans){
       priority_queue<Info*, vector<Info*>, Compare> minHeap;
      
      for(int i = 0; i < K; i++){
            int element = arr[i][0];
            Info* temp = new Info(element, i, 0);
            minHeap.push(temp);
      }
      
      
      while(!minHeap.empty()){
          Info* temp = minHeap.top();
          minHeap.pop();
          
          ans.push_back(temp->data);
          int topData = temp -> data;
          int topRow = temp -> rowIndex;
          int topCol = temp -> colIndex;
          
          if(topCol + 1 < arr[topRow].size()){
              Info* next = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
              minHeap.push(next);
          }
      }
   }
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
      
      vector<int> ans;
      
      mergeKsortedArrays(arr, K, ans);
      return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends