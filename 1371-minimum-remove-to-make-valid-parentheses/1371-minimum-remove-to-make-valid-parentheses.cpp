class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_map<int, int>mp;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if (s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    mp[i]=1;
                }
            }
        }
        while(!st.empty()){
            mp[st.top()]=1;
            st.pop();
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(i) == mp.end()) {
                ans += s[i];  
            }
        }
        return ans;
    }
};