#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void sort012(vector<int>& arr) {
        // code here
        int left = 0;
        int right = arr.size() - 1;
        int mid = 0;

        while (mid <= right) {
            if (arr[mid] == 1) {
                mid++;
            } else if (arr[mid] == 0) {
                swap(arr[left], arr[mid]);
                left++;
                mid++;
            } else {
                swap(arr[mid], arr[right]);
                right--;
            }
        }
    }
};