class Solution {
public:
    string solve(string a, string b){
        int i=0;
        int j=0;
        string ans="";
        while(i<a.length() and j<b.length()){
            if(a[i]==b[i]){
                ans+=a[i];
            }
            else{
                break;
            }
            i++;
            j++;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& str) {
      string ans=str[0];
      for(int i=1; i<str.size(); i++){
        ans=solve(ans,str[i]);
      }
      return ans;
    }
};