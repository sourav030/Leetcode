class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        int n=s1.length();
        for(int i=0; i<s2.length(); i++){
            string s=s2.substr(i,n);
            sort(s.begin(),s.end());
            if(s==s1) return true;
        }
        return false;
    }
};