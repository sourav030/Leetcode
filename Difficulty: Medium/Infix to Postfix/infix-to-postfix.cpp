//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int prec(char c){
       if(c=='^'){
           return 3;
       }
       else if (c=='/' or c=='*'){
           return 2;
       }
       else if (c=='+' or c=='-'){
           return 1;
       }
       else{
           return -1;
       }
   }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
        // Your code here
        stack<char> st;
        string ans="";
        
        for(int i=0; i<s.size(); i++){
            char c=s[i];
            if((c>='a' and c<='z') or (c>='A' and c<='Z') or (c>='0' and c<='9')){
                ans+=c;
            }
            else if (c=='('){
                st.push(c);
            }
            else if (c==')'){
                while(!st.empty() and st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                while(!st.empty() and prec(c)<=prec(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends