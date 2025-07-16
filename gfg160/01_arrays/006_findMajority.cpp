#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int maj1 = -1, maj2 = -1;
        int cnt1 = 0, cnt2 = 0;

        for (auto num : arr) {
            if (maj1 == num) {
                cnt1++;
            } else if (maj2 == num) {
                cnt2++;
            } else if (cnt1 == 0) {
                maj1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                maj2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (auto num : arr) {
            if (num == maj1) {
                cnt1++;
            } else if (num == maj2) {
                cnt2++;
            }
        }

        vector<int> res;
        if (cnt1 > arr.size() / 3) {
            res.push_back(maj1);
        }

        if (cnt2 > arr.size() / 3) {
            res.push_back(maj2);
        }

        if (res.size() > 1 && res[0] > res[1]) {
            swap(res[0], res[1]);
        }

        return res;
    }
};