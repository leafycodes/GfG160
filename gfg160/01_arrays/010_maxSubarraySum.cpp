#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSubarraySum(vector<int> &arr) {
        int max_neg = INT_MIN;
        bool all_neg = true;
        int max_sum = 0;
        int curr_sum = 0;

        for (int num : arr) {
            if (num >= 0) {
                all_neg = false;
            } else {
                max_neg = max(num, max_neg);
            }

            curr_sum += num;
            if (curr_sum < 0) {
                curr_sum = 0;
            }

            max_sum = max(max_sum, curr_sum);
        }

        return all_neg ? max_neg : max_sum;
    }
};