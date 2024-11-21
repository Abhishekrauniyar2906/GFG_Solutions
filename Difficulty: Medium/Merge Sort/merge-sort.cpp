//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  void merge(vector<int> &arr, int l, int r){
      int total_size = r - l + 1;
      int gap = (total_size / 2) + (total_size % 2);
      
      while(gap > 0){
          int i = l;
          int j = i + gap;
          while(j <= r){
              if(arr[i] > arr[j]){
                  swap(arr[i], arr[j]);
              }
              i++;
              j++;
          }
          gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
      }
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r){
            return;
        }
     int mid = l + (r - l) / 2;
     
     mergeSort(arr, l, mid);
     mergeSort(arr, mid + 1, r);
     merge(arr, l, r);
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
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends