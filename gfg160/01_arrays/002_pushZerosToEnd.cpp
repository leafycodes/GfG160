#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int nonZeroIndex = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                arr[nonZeroIndex++] = arr[i];
            }
        }

        while (nonZeroIndex < arr.size()) {
            arr[nonZeroIndex++] = 0;
        }
    }
};