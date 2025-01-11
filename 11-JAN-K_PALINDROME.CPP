#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std ; 

    bool canConstruct(string s, int k) {
        unordered_map <char , int > m ; 
        int n = s.size();

        for(int i =0;i<n;i++){
            m[s[i]]++;
        }
        int even_palin = 0;
        int odd_palin = 0;
        for(auto x : m){
            if(x.second % 2 == 0 ){even_palin = even_palin + x.second/2;}
            else {odd_palin++; even_palin = even_palin + x.second/2;}
        }
 
        if(k<= odd_palin + 2*even_palin && k>= odd_palin){return true;}
        else {return false ;}
    }

    int main(){
        //call your function here  
    }
