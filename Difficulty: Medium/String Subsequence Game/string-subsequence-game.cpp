// User function Template for C++
class Solution {
  public:
    set<string>st;
    unordered_map<char,int>mp;
 
    void solve(string s, int idx, string a){
        if(idx>=s.length()){
            
            int n=a.length()-1;
            if(a!="" and mp.find(a[0])!=mp.end() and mp.find(a[n])==mp.end() )
            st.insert(a);
            
            return;
        }
        a.push_back(s[idx]);
        solve(s,idx+1,a);
        a.pop_back();
        solve(s,idx+1,a);
    }
    set<string> allPossibleSubsequences(string S) {
        // code here
           mp['a']=1;
     mp['e']=1;
      mp['i']=1;
       mp['o']=1;
        mp['u']=1;
        int idx=0;
        string a;
        solve(S,idx,a);
        return st;
    }
};