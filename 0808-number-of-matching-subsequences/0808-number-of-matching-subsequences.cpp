class Solution {
public:
    bool iSolve(string str1,string str2){
        if(str1.length()>str2.length()){
            return false;
        }
        int idx1=0, idx2=0;
        while(idx2<str2.length()){

            if(str1[idx1]==str2[idx2]){
                idx1++;
            }
            idx2++;
        }
        return idx1==str1.length();
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto ele:words){
            mp[ele]++;
        }

        int count=0;
        for(auto ele:mp){
            if(iSolve(ele.first,s)){
                count+=ele.second;
            }
        }

        return count;
    }
};