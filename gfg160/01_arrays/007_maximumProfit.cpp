#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumProfit(vector<int> &prices) {
        int max_profit = 0;
        int n = prices.size();
        int i = 0;

        while (i < n - 1) {
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            if (i >= n - 1) {
                break;
            }
            int buy = i;

            while (i < n - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            int sell = i;

            max_profit += prices[sell] - prices[buy];
            i++;
        }

        return max_profit;
    }
};
