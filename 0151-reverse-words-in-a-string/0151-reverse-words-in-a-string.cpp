class Solution {
public:
    string reverseWords(string s) {
        string word="";
        stack<string>st;
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' ') {
                word+=s[i];
            }
            else if (!word.empty()){
                st.push(word);
                st.push(" ");
                word="";
            }
        }

        if(!word.empty()) st.push(word);
        string ans="";
        if(st.top()==" ") st.pop();
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};