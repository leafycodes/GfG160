#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minRemoval(vector<vector<int>>& intervals) {
        int cnt = 0;
        auto comp = [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; };

        sort(intervals.begin(), intervals.end(), comp);
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                cnt++;
            } else {
                end = intervals[i][1];
            }
        }

        return cnt;
    }
};
