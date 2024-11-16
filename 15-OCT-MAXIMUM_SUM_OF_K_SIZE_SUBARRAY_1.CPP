// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/?envType=daily-question&envId=2024-11-16
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n =nums.size();
        vector<int > diff(n) ;
        vector<int > results;
        diff[0]= 1;
        for(int i=1;i<n;i++){
            diff[i]= nums[i]-nums[i-1];
        }
        int i=k-1;
        while(i< n ){
            bool flag= true;
            for(int j=0;j<k-1;j++){
                if (diff[i-j]!= 1) {flag= false ; break;}
            }
            if (flag== true){
                results.push_back(nums[i]);
            }
            else {
                results.push_back(-1);
            }
            i++;
        }
        return results ;
    }
};