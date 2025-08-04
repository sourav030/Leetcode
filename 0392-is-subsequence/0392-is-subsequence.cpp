class Solution {
public:
    bool solve(string s, string t){
        int i=0;
        int j=0;
        while(j<t.length()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==s.length();
    }
    bool isSubsequence(string s, string t) {
        return solve(s,t);
    }
};