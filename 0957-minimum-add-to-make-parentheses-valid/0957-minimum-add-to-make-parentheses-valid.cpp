class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int count=0;
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(s[i]==')' and !st.empty()){
                    st.pop();
                }
                else{
                    count++;
                }
            }
        }
        return count+st.size();
    }
};