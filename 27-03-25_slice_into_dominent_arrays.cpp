#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int ,int > map ;  
        for(int i = 0 ; i < n ; i++){
            map[nums[i]]++  ; 
        }
        int dominent = 0  ; 
        for(auto & [num  , freq] : map){
            if (freq * 2 > n ) {dominent = num ; break ; } 
        }
        cout<<dominent<<" "; 
        vector<int > index ; 
        for(int i = 0 ; i < n ; i++){
            if (nums[i] == dominent) index.push_back(i) ; 
        }
        int m = index.size() ; 
        for(int i = 0 ; i< m ; i++){
            int no_of_dominent_ele = i+1 ; 
            int size_of_array = index[i] + 1 ; 

            if (size_of_array < no_of_dominent_ele * 2 && n-index[i] -1 < (m - i-1 )*2  ) return size_of_array -1 ; 
        }
        return -1 ; 
    }
};

int main() {}