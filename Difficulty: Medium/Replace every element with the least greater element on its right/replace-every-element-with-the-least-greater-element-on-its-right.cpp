//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Node {
public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
    // Helper function to insert a value and track the successor
    Node* insert(Node* root, int val, int &succ) {
        if (!root) {
            return new Node(val);
        }

        if (val >= root->data) {
            root->right = insert(root->right, val, succ);
        } else {
            succ = root->data; // Update potential successor
            root->left = insert(root->left, val, succ);
        }

        return root;
    }

    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n, -1);
        Node* root = nullptr;

        for (int i = n - 1; i >= 0; --i) {
            int succ = -1;
            root = insert(root, arr[i], succ);
            ans[i] = succ;
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends