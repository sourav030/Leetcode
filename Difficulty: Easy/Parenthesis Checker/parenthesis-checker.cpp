//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isParenthesisBalanced(string& s) {
        // code here
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' or s[i]=='[' or s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(s[i]==')' and !st.empty() and st.top()=='('){
                    st.pop();
                }
                else if(s[i]==']' and !st.empty() and st.top()=='['){
                    st.pop();
                }
                
                else if(s[i]=='}' and !st.empty() and st.top()=='{'){
                    st.pop();
                }
                
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isParenthesisBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends