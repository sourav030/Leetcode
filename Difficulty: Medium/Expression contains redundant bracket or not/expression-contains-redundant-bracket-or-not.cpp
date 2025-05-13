//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char>st;
        
        for(int i=0; i<s.length(); i++){
            if(!st.empty() and st.top()=='(' and s[i]==')') return 1;
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                bool operators=0;
                while(!st.empty() and st.top()!='(' and s[i]==')'){
                    if(st.top()=='+' or st.top()=='-' or st.top()=='*' or st.top()=='/'){
                        operators=1;
                    }
                    st.pop();
                }
                if(!operators) return 1;
                if(st.top()=='('){
                    st.pop();
                }
            }
        }
        return 0;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends