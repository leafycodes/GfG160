#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int res = -1;
        int cnt = 0;

        int i = 0, j = 0;
        while (i < a.size() && j < b.size() && cnt != k) {
            if (a[i] < b[j]) {
                res = a[i];
                i++;
            } else {
                res = b[j];
                j++;
            }

            cnt++;
        }

        while (i < a.size() && cnt != k) {
            res = a[i];
            i++;
            cnt++;
        }

        while (j < b.size() && cnt != k) {
            res = b[j];
            j++;
            cnt++;
        }

        return res;
    }
};