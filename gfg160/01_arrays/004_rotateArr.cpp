#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        int k = d % n;

        for (int i = 0; i < k / 2; i++) {
            swap(arr[i], arr[k - 1 - i]);
        }

        for (int i = 0; i < (n - k) / 2; i++) {
            swap(arr[k + i], arr[n - 1 - i]);
        }

        for (int i = 0; i < n / 2; i++) {
            swap(arr[i], arr[n - 1 - i]);
        }
    }
};