//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int  first(vector<int> &a, int n , int x )
    {
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        int as=-1;
        while(s<=e){
            if(a[mid]==x){
                as=mid;
                e=mid-1;
            }
            else if(a[mid]<x){
                s=mid+1;
            }
            else if(a[mid]>x){
                e=mid-1;
            }
            mid=s+(e-s)/2;
            }
           
        
        return as;
    
}

int last(vector<int>&a, int n,int x){
    int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        int as=-1;
        while(s<=e){
            if(a[mid]==x){
                as=mid;
               s=mid+1;
            }
            else if(a[mid]<x){
                s=mid+1;
            }
            else if(a[mid]>x){
                e=mid-1;
            }
            mid=s+(e-s)/2;
            }
           
        
        return as;
    
}
  
    vector<int> find(vector<int>& a, int x) {
        int n = a.size();
      return{first(a,n,x),last(a,n,x)};
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends