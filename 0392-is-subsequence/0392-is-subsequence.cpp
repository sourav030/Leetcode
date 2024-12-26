class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() > t.length()){
            return 0;
        }
        if(s.length()==1 and t.length()==1){
            if(s[0]==t[0]){
                return 1;
            }
            else{

                return 0;
            }
        }
        int n=s.length()-1;
        int m=t.length()-1;
        int i=0;
        int j=0;
        while(i<=n and j<=m){
            if(s[i]==t[j]){
                s[i]='*';
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i>n){
            return 1;
        }
        return 0;

    }
};