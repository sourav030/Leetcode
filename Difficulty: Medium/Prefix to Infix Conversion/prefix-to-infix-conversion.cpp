//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isOperand(char a) {
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
            return true;
        } else {
            return false;
        }
    }

    string solve(string a){
        for(int i=0; i<a.size(); i++){
            if(a[i]==')'){
                a[i]='(';
            }
            else if (a[i]=='('){
                a[i]=')';
            }
        }
        return a;
    }

    string preToInfix(string exp) {
        stack<string> st;
        for (int i = exp.size()-1; i>=0; i--) {
            // 1. If it's an operand, push it onto the stack
            if (isOperand(exp[i])) {
                string x(1, exp[i]); // Convert char to string
                st.push(x);
            }
            // 2. If it's an operator, pop two operands and form a sub-expression
            else {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                st.push("(" + b + exp[i] + a + ")");
            }
        }
        string a=st.top();
        reverse(a.begin(),a.end());
        
        return solve(a);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends