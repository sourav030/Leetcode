class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n>m){
            return false;
        }
        if(n==1 and m>1){
            if(s[0]==t[0]){
                return true;
            }
        }

        int i=0;
        int j=0;

        while(i<n and j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i==n;
    }
};