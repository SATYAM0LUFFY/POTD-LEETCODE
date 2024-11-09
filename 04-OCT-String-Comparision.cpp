// https://leetcode.com/problems/string-compression-iii/?envType=daily-question&envId=2024-11-09

class Solution {
public:
    string compressedString(string word) {
        int n =word.size();
        int i =0;
        string comp="";
        int count =1;
        char currCount='s';
        while(i<n){
            count = 1 ;
            while(word[i] == word[i+1] && i !=n-1){
                i++;
                count++;
                if (count == 10){
                    comp.push_back( 9 +'0');
                    comp.push_back(word[i]);
                    count = 1 ;
                }
            }
            if (count >0){
            comp.push_back( count +'0');
            comp.push_back(word[i]);
            i++;}
        }
        return comp ;
    }
};