//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isOperand(char a){
        if((a>='a' and a<='z') or (a>='A' and a<='Z') or (a>='0' and a<='9')){
            return true;
        }
        else{
            return false;
        }
    }
    string preToPost(string exp) {
        stack<string>st;
        for(int i=exp.size()-1; i>=0; i--){
            // here we perform two operation
            
            // 1 if it is an operand 
            if(isOperand(exp[i])){
                st.push(string(1,exp[i]));
            }
            else{
                string ele1=st.top();
                st.pop();
                string ele=st.top();
                st.pop();
                st.push((ele1+ele+exp[i]));
            }
            //2 if it is operator
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends