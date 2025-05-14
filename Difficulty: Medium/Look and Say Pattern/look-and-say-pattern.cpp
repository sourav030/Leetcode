//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string next(string s){
        string cur="";
        int count=1;
        for(int i=1; i<s.length(); i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                cur+=to_string(count)+s[i-1];
                count=1;
            }
        }
        cur+=to_string(count)+s.back();
        return cur;
    }
    string countAndSay(int n) {
        // code here
        if(n==1) return "1";
        
        
        string ans=countAndSay(n-1);
        
        return next(ans);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends