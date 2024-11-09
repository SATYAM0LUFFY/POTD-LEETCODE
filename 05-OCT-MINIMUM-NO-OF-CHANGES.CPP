//https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/?envType=daily-question&envId=2024-11-09

class Solution {
public:
    int minChanges(string s) {
        int  c= 0;
        int n =s.size();
        int i = 0;
        while(i<n){
            if(s[i] != s[i+1]){c+=1;}
            i+=2;
        }
        return c;
    }
};