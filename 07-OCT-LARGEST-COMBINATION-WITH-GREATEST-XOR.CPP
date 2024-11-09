//https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/?envType=daily-question&envId=2024-11-09

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCount = 0;
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;
                }
            }

            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};
