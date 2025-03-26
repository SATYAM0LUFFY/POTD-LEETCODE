#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diff(int a , int b){
        if (a> b) return a - b ; 
        return b - a ; 
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        int n =  grid.size() ; 
        int m =  grid[0].size() ;
        vector<int > nums  ; 
        int a = grid[0][0] ; 
        for(int i = 0; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if (diff(a ,grid[i][j] ) % x != 0) return -1  ; 
                nums.push_back(grid[i][j])  ; 
            }
        }
        sort(nums.begin() , nums.end()) ; 
        n = nums.size() ; 
        if(n ==1) return 0 ;
        int mid  = n /2 ;
        int midV = nums[mid] ; 
        int ans = 0  ;
        for(int i = 0 ; i < n ; i++){
            ans += (diff(nums[i] , midV) / x) ; 
        } 
        return ans  ; 

    }
};

int main(){
    
}