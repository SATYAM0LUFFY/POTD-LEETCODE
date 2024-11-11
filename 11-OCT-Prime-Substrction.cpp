// https://leetcode.com/problems/prime-subtraction-operation/description/?envType=daily-question&envId=2024-11-11

class Solution {
public:
    bool isPrime(int n){
        if(n==1 | n==0) return false ;
        for(int i =2;i<=sqrt(n) ; i++){
            if(n%i == 0) return false;
        }
        return true ;
    }
    bool isSame(vector<int >v){
        int n =v.size();
        for(int i =0;i<n-1;i++){if(v[i] == v[i+1]){return false ;}}
        return true ;
    } 
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size() ; 
        for(int i =0;i<n;i++){
            for(int j= nums[i] -1 ; j>=2;j--){
                if(i==0 && isPrime(j) ){nums[i] -= j;break;}
                else if(isPrime(j) && nums[i]-j >nums[i-1]){nums[i] -= j;break;}
                
            }
            cout<<nums[i]<<endl;
            if(i != n-1 && nums[i] >= nums[i+1]){return false ;}
            if( i != 0 && nums[i] <= nums[i-1]) {return false ;}
            vector<int > V = nums;
            sort(V.begin() , V.end());
            if(nums == V &&  isSame(nums)) return true ;
        }
        return false  ;
    }
};