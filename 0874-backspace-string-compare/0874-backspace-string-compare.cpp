class Solution {
public:
    string solve(string s){
        stack<char>st;
        int i=0;
        int j=s.length();
        while(i<j){
            if(s[i]!='#'){
                st.push(s[i]);
            }
            else if(!st.empty()){
                st.pop();
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        string s1=solve(s);
        string s2=solve(t);
        return s1==s2;
    }
};