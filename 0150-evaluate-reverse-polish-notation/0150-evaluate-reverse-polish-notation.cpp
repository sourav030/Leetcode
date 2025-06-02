class Solution {
public:
    int evalRPN(vector<string>& token) {
        stack<int>st;
        int ans=0;
        for(int i=0; i<token.size(); i++){
            if(token[i]!="+" and token[i]!="-" and token[i]!="*" and token[i]!="/")
            {
                int val=stoi(token[i]);
                st.push(val);
            }
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                string str=token[i];
                if(str=="+"){
                    st.push(b+a);
                }
                else if(str=="-"){
                    st.push(b-a);
                }
                else if (str=="*"){
                    st.push(a*b);
                }
                else if(str=="/"){
                    st.push(b/a);
                }
            }
        }
        ans=st.top();
        return ans;
    }
};