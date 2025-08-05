#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals,
                                       vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return mergeOverlap(intervals);
    }

    vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& prev = res.back();
            if (intervals[i][0] <= prev[1]) {
                prev[1] = max(prev[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};