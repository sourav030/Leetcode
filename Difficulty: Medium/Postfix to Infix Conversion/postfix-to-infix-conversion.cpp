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

    string postToInfix(string exp) {
        stack<string> st;
        for (int i = 0; i < exp.size(); i++) {
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
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    fclose(stdout);

    return 0;
}

// } Driver Code Ends