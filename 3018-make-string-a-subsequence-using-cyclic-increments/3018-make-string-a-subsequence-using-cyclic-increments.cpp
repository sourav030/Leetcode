class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        int j=0;
        while(i<str1.length() and j<str2.length()){
            char ch=str1[i];
            char nextChar=ch=='z'? 'a': ch+1;
            if(ch==str2[j] or nextChar==str2[j]){
                j++;
            }
            i++;
        }
        return j==str2.length();
    }
};