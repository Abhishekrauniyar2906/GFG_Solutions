//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:

    void heapify(vector<int> &arr, int n, int index) {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        int largestIndex = index;

        if (leftIndex < n && arr[leftIndex] > arr[largestIndex]) {
            largestIndex = leftIndex;
        }

        if (rightIndex < n && arr[rightIndex] > arr[largestIndex]) {
            largestIndex = rightIndex;
        }

        if (index != largestIndex) {
            swap(arr[index], arr[largestIndex]);
            heapify(arr, n, largestIndex);  // Recurse with correct new index
        }
    }

    void heapSort(vector<int>& arr) {
        int n = arr.size();

        // Build Max Heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);   // Move current root to end
            heapify(arr, i, 0);     // Heapify the reduced heap
        }
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
        obj.heapSort(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends