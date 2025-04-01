#include <bits/stdc++.h>
using namespace std  ; 

class Solution {
public:
    vector<vector<int > > questions ; 
    long long f(int  i , vector<long long int >& dp ){
        if (i >= questions.size()) return  0 ; 
        if (dp[i] != -1 ) return dp[i] ; 
        if (i == questions.size() -1 ) return questions[i][0] ; 
        vector<int > qu = questions[i] ; 
        return dp[i] =  max(
            qu[0] + f(i+qu[1] +1  , dp )  , 
            f(i+1 , dp )
        ) ; 
    }
    long long mostPoints(vector<vector<int>>& q) { 
        questions = q ; 
        int n = questions.size()  ;
        vector<long long int > dp(n , -1 ) ; 
        return f( 0 , dp ) ; 
    }
}; 

int main(){

}