class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0; i<tokens.size(); i++){
            string ele=tokens[i];
            if(ele=="+" or ele=="-" or ele=="*" or ele=="/"){
                if(ele=="+"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int val=b+a;
                    st.push(val);
                }
                else if(ele=="-"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int val=b-a;
                    st.push(val);
                }
                else if(ele=="*"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int val=b*a;
                    st.push(val);
                }
                else{
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int val=b/a;
                    st.push(val);
                }
            }
            else{
                int val=stoi(ele);
                st.push(val);
            }
        }
        return st.top();
    }
};