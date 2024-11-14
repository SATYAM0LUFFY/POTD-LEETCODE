// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/?envType=daily-question&envId=2024-11-14

class Solution {
public:
    bool canDistribute(int maxItemsPerStore, int n, vector<int>& quantities) {
        int storesRequired = 0;
        for (int quantity : quantities) {
            storesRequired += (quantity + maxItemsPerStore - 1) / maxItemsPerStore;
        }
        return storesRequired <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canDistribute(mid, n, quantities)) {
                result = mid; 
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }

        return result;
    }
};
