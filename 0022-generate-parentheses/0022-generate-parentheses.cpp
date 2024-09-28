class Solution {
        void solve(vector<string>&ans,int n,int left,int right , string &s)
        {
                if(left+right==2*n)
                {
                        ans.push_back(s);
                }
                if(left<n)
                {
                        s.push_back('(');
                        solve(ans,n,left+1,right,s);
                        s.pop_back();
                }
                if(right<left){
                        s.push_back(')');
                        solve(ans,n,left,right+1,s);
                        s.pop_back();
                }
        }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
            int left=0;
            int right=0;
            string s;
            solve(ans,n,left,right,s);
            return ans;
    }
};