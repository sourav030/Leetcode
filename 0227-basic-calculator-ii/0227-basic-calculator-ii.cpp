class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int number=0;
        char lastOp='+';
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i])){
                number=number*10+(s[i]-'0');
            }
            if(!isdigit(s[i]) and s[i]!=' ' || i==s.length()-1){
                if(lastOp=='+'){
                    st.push(number);
                }
                if(lastOp=='-'){
                    st.push(-number);
                }
                if(lastOp=='*'){
                    int prev=st.top();
                    st.pop();
                    st.push(prev*number);
                }
                if(lastOp=='/'){
                    int prev=st.top();
                    st.pop();
                    st.push(prev/number);
                }
                number=0;
                lastOp=s[i];
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};