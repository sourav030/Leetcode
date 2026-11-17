class Solution {
public:
    string solve(string ans, string str){
        int i=0;
        int j=0; 
        string a="";
        while(i<ans.length() and j<str.length() and ans[i]==str[j]){
            a+=ans[i];
            i++;
            j++;
        }
        return a;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<=0){
            return "";
        }
        string ans=strs[0];
        for(int i=0; i<strs.size(); i++){
            ans=solve(ans,strs[i]);
        }
        return ans;

    }
};