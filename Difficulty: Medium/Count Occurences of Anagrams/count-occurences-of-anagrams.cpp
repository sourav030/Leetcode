// User function template for C++
class Solution {
  public:
    
    bool check(unordered_map<char,int>mp, string s){
        for(auto ele:mp){
            if(ele.second>0){
                return false;
            }
        }
        return true;
    }
    int search(string &pat, string &txt) {
        // code here
        unordered_map<char,int>mp;
        for(auto ele:pat){
            mp[ele]++;
        }
        int start=0;
        int end=0;
        int count=0;
        while(end<txt.length()){
            mp[txt[end]]--;
            if(end-start+1==pat.length()){
                if(check(mp,pat)){
                    count++;
                }
                mp[txt[start]]++;
                start++;
            }
            end++;
        }
        return count;
    }
};