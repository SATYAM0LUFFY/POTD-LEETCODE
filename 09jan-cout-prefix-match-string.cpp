#include <iostream>
#include <vector>
using namespace std ; 


int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int k = pref.size();
        int count = 0 ;
        for(int i =0 ; i<n ; i++){
            if(words[i].substr(0,k) == pref){count++;}
        }return count ;
}
int main(){
    // call your function here 
}
