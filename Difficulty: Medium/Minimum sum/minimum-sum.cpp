#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string &a, string &b) {
        string result = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int n1 = (i >= 0) ? a[i--] - '0' : 0;
            int n2 = (j >= 0) ? b[j--] - '0' : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            result += (sum % 10 + '0');
        }

        reverse(result.begin(), result.end());
        
        // Remove any leading zeros if present
        int pos = 0;
        while (pos < result.size() && result[pos] == '0') pos++;
        if (pos == result.size()) return "0"; // All zeros
        return result.substr(pos);
    }

    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());

        string num1 = "", num2 = "";

        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0)
                num1 += to_string(arr[i]);
            else
                num2 += to_string(arr[i]);
        }

        return addStrings(num1, num2);
    }
};
