#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
   public:
    string trim_zeroes(string& str) {
        size_t first = str.find('1');
        return first == string::npos ? "0" : str.substr(first);
    }

    string addBinary(string& s1, string& s2) {
        // your code here
        s1 = trim_zeroes(s1);
        s2 = trim_zeroes(s2);

        int n = s1.size();
        int m = s2.size();

        if (n < m) {
            return addBinary(s2, s1);
        }

        int j = m - 1;
        int carry = 0;
        for (int i = n - 1; i >= 0; i--) {
            int bit1 = s1[i] - '0';
            int sum = bit1 + carry;

            if (j >= 0) {
                int bit2 = s2[j] - '0';
                sum += bit2;
                j--;
            }

            int bit = sum % 2;
            carry = sum / 2;

            s1[i] = (char)(bit + '0');
        }

        if (carry == 1) {
            s1 = '1' + s1;
        }

        return s1;
    }
};