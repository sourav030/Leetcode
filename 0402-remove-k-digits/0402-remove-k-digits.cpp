class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0; i<num.length(); i++){
            while(!st.empty() and k>0 and st.top()-'0' > num[i]-'0')
            {
                st.pop();
                k=k-1;
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
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        while(ans.size()!=0 and ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if(ans.size()==0) return "0";
        return ans;
        
    }
};