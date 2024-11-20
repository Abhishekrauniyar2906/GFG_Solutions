//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // Helper function to check if the move is valid
    bool isSafe(vector<vector<int>> &mat, int row, int col, int newX, int newY, vector<vector<bool>> &visited) {
        if ((newX >= 0 && newX < row) && 
            (newY >= 0 && newY < col) && 
            (mat[newX][newY] == 1) && 
            (visited[newX][newY] == false)) {
            return true;
        }
        return false;
    }

    // Recursive function to explore all paths
    void printAllpaths(vector<vector<int>> &mat, int row, int col, int srcX, int srcY, 
                       string &output, vector<vector<bool>> &visited, vector<string> &result) {
        if (srcX == row - 1 && srcY == col - 1) { // Reached destination
            result.push_back(output);
            return;
        }

        // Down
        int newX = srcX + 1;
        int newY = srcY;
        if (isSafe(mat, row, col, newX, newY, visited)) {
            visited[newX][newY] = true;
            output.push_back('D');
            printAllpaths(mat, row, col, newX, newY, output, visited, result);
            output.pop_back();
            visited[newX][newY] = false;
        }

        // Right
        newX = srcX;
        newY = srcY + 1;
        if (isSafe(mat, row, col, newX, newY, visited)) {
            visited[newX][newY] = true;
            output.push_back('R');
            printAllpaths(mat, row, col, newX, newY, output, visited, result);
            output.pop_back();
            visited[newX][newY] = false;
        }

        // Left
        newX = srcX;
        newY = srcY - 1;
        if (isSafe(mat, row, col, newX, newY, visited)) {
            visited[newX][newY] = true;
            output.push_back('L');
            printAllpaths(mat, row, col, newX, newY, output, visited, result);
            output.pop_back();
            visited[newX][newY] = false;
        }

        // Up
        newX = srcX - 1;
        newY = srcY;
        if (isSafe(mat, row, col, newX, newY, visited)) {
            visited[newX][newY] = true;
            output.push_back('U');
            printAllpaths(mat, row, col, newX, newY, output, visited, result);
            output.pop_back();
            visited[newX][newY] = false;
        }
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<string> result;

        // If starting point is blocked
        if (mat[0][0] == 0) {
            return result;
        }

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        string output = "";

        visited[0][0] = true;
        printAllpaths(mat, row, col, 0, 0, output, visited, result);

        return result;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends