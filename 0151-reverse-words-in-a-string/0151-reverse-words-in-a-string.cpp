class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string word="";
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' '){
                word+=s[i];
            }
            else{
                if(!word.empty()){
                    st.push(word);
                }
                word="";
            }
        }
        if(!word.empty()){
            st.push(word);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()){
                ans+=" ";
            }
        }
        return ans;
    }
};