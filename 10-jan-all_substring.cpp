#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int count2 = words2.size();
        vector<string > output ;
        unordered_map <char ,  int > mainm  ; 
        unordered_map <char  , int > m;
        for(int i =0;i<count2 ; i++){
            m.clear();
            for(int j =0;j<words2[i].size() ; j++){
                m[words2[i][j]]++;
            }
            // for(auto x : m){cout<<x.first<<" "<<x.second<<endl;}
            for(auto x : m){
                if(mainm[x.first] < x.second){
                    mainm[x.first] = x.second;
                }
            }
        }

        // for(auto x : mainm){cout<<x.first<<" "<<x.second<<endl;}

        int count1=  words1.size();
        unordered_map <char , int > checkm;

        for(int i =0;i<count1 ; i++){
            checkm.clear();
            for(int j = 0;j<words1[i].size() ; j++){
                checkm[words1[i][j]]++;
            }
            bool bol  = true ;
            for(auto x : mainm){
                if(mainm[x.first] > checkm[x.first]){bol  = false ;break;}
            }
            if(bol){output.push_back(words1[i]);}
        }
        return output ;
}

int main(){
    //WRITE YOUR CODE TO CALL THE FUNCTION HERE 
}