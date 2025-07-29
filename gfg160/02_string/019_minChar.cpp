#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minChar(string &str) {
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        string temp = str + '#' + revStr;
        int n_temp = temp.length();

        vector<int> lps(n_temp, 0);
        int len = 0;
        int i = 1;

        while (i < n_temp) {
            if (temp[i] == temp[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int lps_len = lps[n_temp - 1];
        return str.size() - lps_len;
    }
};
