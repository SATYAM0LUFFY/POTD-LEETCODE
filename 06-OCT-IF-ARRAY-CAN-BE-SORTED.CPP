class Solution {
public:
    int countBit(int n ){
        int c = 0;
        while(n!=0){
            n = (n & (n-1));
            c++;
        }
        return c ;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int > bits(n);
        for(int i =0;i<n;i++){
            bits[i] = countBit(nums[i]);
        }
        int l = 0;
        int h = 0;
       while(h<n){
        if(bits[l] == bits[h]){h++;}
        else {
            sort(nums.begin() +l , nums.begin() + h);
            l = h ;
        }
       }
       sort(nums.begin() + l , nums.end());
       vector<int > ans  = nums;
       sort(ans.begin() , ans.end());
       if (ans == nums){return true ;}
       return false; 
    }
};