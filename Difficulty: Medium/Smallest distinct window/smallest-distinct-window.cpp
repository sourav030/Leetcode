//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        set<char>st(str.begin(),str.end());
        
        int n=st.size();
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int ans=INT_MAX;
        while(j<str.length()){
            mp[str[j]]++;
            if(mp.size()>=n){
                while(mp[str[i]]>1){
                    mp[str[i]]--;
                    i++;
                }
                ans=min(ans,j-i+1);
                
            }
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends