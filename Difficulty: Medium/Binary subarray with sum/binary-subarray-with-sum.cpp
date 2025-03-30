//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        // Your code goes here.
        int sum = 0;
        int s = 0;
        int e = 0;

        int count = 0;
        int prefixcount = 0;
        while(e < nums.size()){
            sum += nums[e];
            while(s < e && (nums[s] == 0 || sum > goal)){

                if(nums[s] == 1){
                    prefixcount = 0;
                }
                else{
                    prefixcount += 1;
                }
               sum = sum - nums[s];
                s++;
            }
                if(sum == goal){
                    count += prefixcount + 1;
                }

                e++;
                     }
       return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<int> arr;
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.numberOfSubarrays(arr, target) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends