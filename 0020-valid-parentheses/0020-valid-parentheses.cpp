class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto ele:s){
            if(ele=='(' or ele=='[' or ele=='{'){
                st.push(ele);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if(ele==')' and st.top()=='('){
                    st.pop();
                }
                 else if(ele==']' and st.top()=='['){
                    st.pop();
                }
                 else if(ele=='}' and st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};