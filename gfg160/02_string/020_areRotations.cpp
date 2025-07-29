#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    bool areRotations(string &s1, string &s2) {
        // code here
        if (s1.size() != s2.size()) {
            return false;
        }

        string newStr = s2 + s2;
        return newStr.find(s1) != string::npos;
    }
};