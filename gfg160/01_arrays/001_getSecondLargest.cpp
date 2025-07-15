#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getSecondLargest(vector<int> &arr) {
        if (arr.size() < 2) {
            return -1;
        }
        int max = INT_MIN;
        int smax = INT_MIN;
        for (auto it : arr) {
            if (it > max) {
                smax = max;
                max = it;
            } else if (it > smax && it != max) {
                smax = it;
            }
        }

        return smax != INT_MIN ? smax : -1;
    }
};