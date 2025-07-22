#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int total_sum = arr[0];
        int total_max = arr[0];
        int total_min = arr[0];
        int curr_max = arr[0];
        int curr_min = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            curr_min = min(arr[i], curr_min + arr[i]);
            curr_max = max(arr[i], curr_max + arr[i]);
            total_min = min(total_min, curr_min);
            total_max = max(total_max, curr_max);

            total_sum += arr[i];
        }

        // total min is equal to total sum only if all numbers are negative
        if (total_sum == total_min) {
            return total_max;
        }

        return max(total_max, total_sum - total_min);
    }
};