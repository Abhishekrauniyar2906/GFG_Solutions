//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
  void solve(vector<int> &arr, string &current, int index, vector<string> &result, vector<string> &mapping){
      if(index >= arr.size()){
          result.push_back(current);
          return;
      }
      
      string letters = mapping[arr[index] - 2];
      for(char ch : letters){
          current.push_back(ch);
          solve(arr, current, index + 1, result, mapping);
          current.pop_back();
      }
  }
    vector<string> possibleWords(vector<int> &arr) {
       vector<string>mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
       vector<string>result;
       string current = "";
       solve(arr, current, 0, result, mapping);
       return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        vector<string> v = obj.possibleWords(a);
        sort(v.begin(), v.end());
        Array::print(v);
        cout << "~" << endl;
    }
}

// } Driver Code Ends