class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length();
        vector<int>ans(n);
        for(int i=0; i<s.length(); i++){
            int index=INT_MAX;
            for(int j=0; j<s.length(); j++){
                if(s[j]==c){
                    index=min(index,abs(j-i));
                }
            }
            ans[i]=index;
        }
        return ans;
    }
};