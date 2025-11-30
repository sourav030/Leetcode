class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        
        for(char ele : s){
            if(ele != ']'){
               
                string temp(1, ele); 
                st.push(temp);
            }
            else{
                string curr_str = "";
                
              
                while(!st.empty() && st.top() != "["){
                    curr_str = st.top() + curr_str; 
                    st.pop();
                }
                
           
                if(!st.empty() && st.top() == "[")
                    st.pop();

                string num_str = "";
                
             
                while(!st.empty() && isdigit(st.top()[0])){
                    num_str = st.top() + num_str; 
                    st.pop();
                }
                
                int n = stoi(num_str);
                string decoded = "";
                while(n--){
                    decoded += curr_str;
                }
                st.push(decoded);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};