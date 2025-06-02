class Solution {
public:
    string smallestNumber(string pattern) {
        string nums="";
        int counter=1;
        int n=pattern.length();
        stack<char>st;
        for(int i=0; i<=n; i++){
            st.push(counter+'0');
            counter++;
            if(i==n or pattern[i]=='I'){
                while(!st.empty()){
                    nums+=st.top();
                    st.pop();
                }
            }
        }
        return nums;
    }
};