//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        if (nums[0] == 0) return -1;

        int jumps = 0;
        int l = 0, r = 0;

        while (r < n - 1) {
            int farthest = r;
            for (int i = l; i <= r; ++i) {
                farthest = max(farthest, i + nums[i]);
            }

            if (farthest == r) {
                // Stuck: Cannot move further
                return -1;
            }

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends