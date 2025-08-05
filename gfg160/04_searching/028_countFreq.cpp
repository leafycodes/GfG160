#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int countFreq(vector<int>& arr, int target) {
        int cnt = 0;
        for (int el : arr) {
            if (el == target) {
                cnt++;
            }
        }

        return cnt;
    }
};
