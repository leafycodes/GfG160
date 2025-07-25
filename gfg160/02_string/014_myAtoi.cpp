#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int myAtoi(string& s) {
        int res = 0;
        int i = 0;
        bool neg = false;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        if (i < s.size() && s[i] == '-') {
            neg = true;
            i++;
        } else if (i < s.size() && s[i] == '+') {
            i++;
        }

        while (s[i] >= '0' && s[i] <= '9') {
            // overflow handling
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7)) {
                return neg ? INT_MIN : INT_MAX;
            }

            res = res * 10 + (s[i++] - '0');
        }

        return neg ? -res : res;
    }
};