#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void reverseArray(vector<int> &arr) {
        // code here
        for (int i = 0; i < arr.size() / 2; i++) {
            swap(arr[i], arr[arr.size() - 1 - i]);
        }
    }
};