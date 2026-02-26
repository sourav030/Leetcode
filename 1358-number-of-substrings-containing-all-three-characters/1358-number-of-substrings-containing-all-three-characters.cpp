class Solution {
public:

    int numberOfSubstrings(string s) {
        int ans=0;
        for(int i=0; i<s.length(); i++){
            bool a=0;
            bool b=0;
            bool c=0;
            for(int j=i; j<s.length(); j++){
                if(s[j]=='a') a=1;
                if(s[j]=='b') b=1;
                if(s[j]=='c') c=1;
                if(a and b and c) {
                    ans+=s.length()-j;
                    break;
                }
                
            }
        }
        return ans;
    }
};