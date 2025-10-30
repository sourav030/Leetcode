class Solution {
public:
    string solve(string a, string b){
        int i=0;
        int j=0;
        string ans="";
        while(i<a.length() and j<b.length() and a[i]==b[j]){
            ans+=a[i];
            i++;
            j++;
        }
        return ans;

    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];

        for(int i=1; i<strs.size(); i++){
            ans=solve(ans,strs[i]);
        }
        return ans;
    }
};