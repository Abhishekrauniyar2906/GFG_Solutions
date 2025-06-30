// User function template for C++
class Solution {
  public:
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        // code here
        return accumulate(arr.begin(), arr.end(), 0);
    }
};