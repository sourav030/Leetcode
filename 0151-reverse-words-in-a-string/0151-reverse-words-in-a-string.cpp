class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string word="";
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' '){
                word+=s[i];
            }
            else{
               if(ans.empty() and !word.empty()) ans+=word;
               else if(!ans.empty() and !word.empty()){
                 ans=word+" "+ans;
               }
               word="";
            }
        }
        if(!word.empty()){
            if(ans.empty()){
                ans+=word;
                return ans;
            }
            ans=word+" "+ans;
        }
        return ans;
    }
};