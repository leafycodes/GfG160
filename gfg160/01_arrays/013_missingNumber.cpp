#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int missingNumber(vector<int> &arr) {
        // code here
        // i used the cycle sort algorithm
        // basically swap the numbers into their correct
        // positions as we encounter -> O(n).
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (1 <= arr[i] && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i != arr[i - 1]) {
                return i;
            }
        }

        return n + 1;
    }
};