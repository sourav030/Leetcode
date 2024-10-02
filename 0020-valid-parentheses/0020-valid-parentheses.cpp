class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            { if(!st.empty()){
               char x=st.top();
               if(s[i]==')' and x=='(' and !st.empty())
               {
                   st.pop();
               }
               else if(s[i]==']' and x=='[' and !st.empty())
               {
                   st.pop();
               }
               else if(s[i]=='}' and x=='{' and !st.empty())
               {
                   st.pop();
               }
               else
               {
                   return false;
               }

            }else
               {
                   return false;
               }
            }
        }
        if(st.empty())
        {
            return true;
        }
        else{
            return false;
        }
    }
};