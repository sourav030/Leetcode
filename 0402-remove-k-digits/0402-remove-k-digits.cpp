class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char>st;
        for(int i=0; i<num.length(); i++){
            while(!st.empty() and st.top()-'0'>num[i]-'0' and k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() and k>0){
            st.pop();
            k--;
        }
        if(st.empty()){
            return "0";
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        while(!ans.empty() and ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0) return "0";
        return ans;
    }
};