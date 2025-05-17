class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<pair<char,int>>st;
        string ans="";
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(make_pair(s[i],i));
            }
            else if(s[i]==')' and !st.empty()){
                int index=st.top().second;
                st.pop();
                if(st.empty()){
                    ans+=s.substr(index+1,i-index-1);
                }
            }
        }
        return ans;
    }
};