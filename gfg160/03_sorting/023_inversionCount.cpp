#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int cnt = 0;

        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                cnt += (mid - i + 1);  // rem elements in left
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (int i = left; i <= right; i++) {
            arr[i] = temp[i - left];
        }

        return cnt;
    }

    int merge_sort(vector<int>& arr, int left, int right) {
        int cnt = 0;

        if (left < right) {
            int mid = left + (right - left) / 2;
            cnt += merge_sort(arr, left, mid);       // left subaray
            cnt += merge_sort(arr, mid + 1, right);  // right subarray
            cnt += merge(arr, left, mid, right);     // count and merge
        }

        return cnt;
    }

    int inversionCount(vector<int>& arr) {
        // Code Here
        return merge_sort(arr, 0, arr.size() - 1);
    }
};