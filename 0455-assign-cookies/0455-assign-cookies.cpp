class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;// greedy factor
        int j=0;// size of cookie
        int n=g.size();
        int m=s.size();
        int ans=0;
        while(j<m){
            if(i<n){
                 if(g[i] <= s[j]){
                i+=1;
                ans+=1;
            }
            }
           
            j+=1;
        }
        return ans;
    }
};