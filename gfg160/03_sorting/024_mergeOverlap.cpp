#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class compare {
   public:
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};

class Solution {
   public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        if (arr.empty()) {
            return {};
        }
        sort(arr.begin(), arr.end(), compare());
        vector<vector<int>> res;
        res.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            vector<int>& prev = res.back();
            if (arr[i][0] <= prev[1]) {
                prev[1] = max(prev[1], arr[i][1]);
            } else {
                res.push_back(arr[i]);
            }
        }

        return res;
    }
};