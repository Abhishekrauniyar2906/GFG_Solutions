//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
  
  bool isPossible(int n, int arr[], int m, int mid){
      int student_count = 1;
      int page_sum = 0;
    
      for(int i = 0; i < n; i++)
{
     // Here we are adding the value one by one accoring to the mid the value
    if(page_sum + arr[i] <= mid){
        page_sum = page_sum + arr[i];
        
    }
    else{
        student_count++;
    
    if(student_count > m || arr[i] > mid){
        return false;
    }
    page_sum = arr[i];
    }
    
}  
      return true;
  }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m>n){
            return -1;
        }
       int s = 0;
        int sum = 0;
        int ans = -1;
        for(int i = 0; i < n; i++){
            sum = sum + arr[i];
        }
        int e = sum;
         int mid = s + (e-s)/2; 
        while(s <= e){
           
            if(isPossible(n,arr,m,mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
              mid = s + (e-s)/2; 
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends