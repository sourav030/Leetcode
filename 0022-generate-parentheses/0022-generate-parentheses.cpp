class Solution {
public:

    void solve(vector<string> &ans, string s, int left,int right, int n){
        if(left+right==n*2){
            ans.push_back(s);
            return ;
        }
        if(left<n){
            s.push_back('(');
            solve(ans,s,left+1,right,n);
            s.pop_back();
        }
        if(right<left){
            s.push_back(')');
            solve(ans,s,left, right+1,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
     int left=0;
     int right=0;
     string s="";
     vector<string> ans;
     solve(ans,s,left,right, n);
     return ans;   
    }
};