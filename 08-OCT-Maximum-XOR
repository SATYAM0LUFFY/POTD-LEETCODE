// https://leetcode.com/problems/maximum-xor-for-each-query/?envType=daily-question&envId=2024-11-09

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int q=  0;
        int n =nums.size();
        int u = (1<< maximumBit) -1;
        int w= 0 ;
        vector<int > ans ;
        for(int i =0;i<n;i++){
            q ^= nums[i];
            w= q & u;
            ans.push_back(w ^ u);
        }
        reverse(ans.begin() , ans.end());
        return ans ;
        
    }
};