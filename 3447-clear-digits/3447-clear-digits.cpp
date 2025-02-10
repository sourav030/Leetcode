class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        string ans="";
        for(int i=0; i<s.length(); i++){
            if(s[i]>='a' and s[i]<='z'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};