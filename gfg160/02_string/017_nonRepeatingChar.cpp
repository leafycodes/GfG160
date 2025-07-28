#include <iostream>
#include <map>
using namespace std;

class Solution {
   public:
    char nonRepeatingChar(string &s) {
        map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        for (char ch : s) {
            if (mp[ch] == 1) {
                return ch;
            }
        }

        return '$';
    }
};
