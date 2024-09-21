//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  vector<int> commonElements(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    int i = 0, j = 0, k = 0;
    vector<int> ans;
    
    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        // If all elements are the same, this is a common element
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            // Add to result only if it's not a duplicate
            if (ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
            k++;
        }
        // Increment the pointer of the smallest element to find a match
        else if (arr1[i] < arr2[j]) {
            i++;
        } 
        else if (arr2[j] < arr3[k]) {
            j++;
        } 
        else {
            k++;
        }

        // Skip duplicates in arr1
        while (i > 0 && i < arr1.size() && arr1[i] == arr1[i - 1]) i++;
        // Skip duplicates in arr2
        while (j > 0 && j < arr2.size() && arr2[j] == arr2[j - 1]) j++;
        // Skip duplicates in arr3
        while (k > 0 && k < arr3.size() && arr3[k] == arr3[k - 1]) k++;
    }

    // If no common elements, return [-1]
    if (ans.empty()) {
        return {-1};
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
        vector<int> arr, brr, crr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        string input3;
        getline(cin, input3);
        stringstream ss3(input3);
        int number3;
        while (ss3 >> number3) {
            crr.push_back(number3);
        }
        Solution ob;
        vector<int> res = ob.commonElements(arr, brr, crr);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}
// } Driver Code Ends