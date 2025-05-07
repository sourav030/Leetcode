class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        bool first=1;
        int i=0;
        int j=0;
        while(i<word1.length() and j<word2.length()){
            if(first){
                ans+=word1[i];
                i++;
                first=0;
            }
            else{
                ans+=word2[j];
                j++;
                first=1;
            }
        }
        while(i<word1.length()){
            ans+=word1[i];
            i++;
        }
        while(j<word2.length()){
            ans+=word2[j];
            j++;
        }
        return ans;
    }
};