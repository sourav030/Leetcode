class Solution {
public:
    string solve(string s1, string s2){
        int i=0, j=0;
        int n1=s1.length();
        int n2=s2.length();
        string ans="";
        while(i<n1 and j<n2){
            if(s1[i]==s2[j]){
                ans+=s1[i];
            }
            else{
                break;
            }
            i++;
            j++;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=0; i<strs.size(); i++){
            ans=solve(ans,strs[i]);
        }
        return ans;
    }
};