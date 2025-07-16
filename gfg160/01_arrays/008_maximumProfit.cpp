#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int min_price = INT_MAX;
        int max_profit = 0;

        for (auto price : prices) {
            if (price < min_price) {
                min_price = price;
            } else if (price - min_price > max_profit) {
                max_profit = price - min_price;
            }
        }

        return max_profit;
    }
};
