#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> search(string &pat, string &txt) {
        // code here
        vector<int> res;
        int m = pat.size();
        int n = txt.size();
        if (m == 0 || n == 0 || m > n) {
            return res;
        }

        vector<int> lps(m, 0);  // knuth-morris-pratt algo
        compute_lps(pat, lps);

        int i = 0;
        int j = 0;
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return res;
    }

   private:
    void compute_lps(string pat, vector<int> &lps) {
        int len = 0;
        int i = 1;
        int m = pat.size();
        lps[0] = 0;

        while (i < m) {
            if (pat[i] == pat[len]) {
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
    }
};