#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getMinDiff(vector<int> &arr, int k) {
        if (arr.size() == 0) {
            return 0;
        }

        sort(arr.begin(), arr.end());
        int n = arr.size();
        int res = arr[n - 1] - arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < k) {
                continue;
            }

            int minh = min(arr[0] + k, arr[i] - k);
            int maxh = max(arr[i - 1] + k, arr[n - 1] - k);

            res = min(res, maxh - minh);
        }

        return res;
    }
};