#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<int> &arr) {
        int max_prod = INT_MIN;
        int n = arr.size();
        int ltr = 1;
        int rtl = 1;

        for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            if (ltr == 0) {
                ltr = 1;
            }

            if (rtl == 0) {
                rtl = 1;
            }

            ltr *= arr[i];
            rtl *= arr[j];

            // can use nested max for simplicity
            max_prod = max({max_prod, ltr, rtl});
            // std::initializer_list -> {} to pass multiple values
        }

        return max_prod;
    }
};