class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>v;
        for(int i=0; i<s.size(); i++)
        {
             if(isalnum(s[i])) {
            v.push_back(tolower(s[i]));
        }
        }
        int j=v.size()-1;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]!=v[j])
            {
                return false;
            }
            j--;
        }
        return true;
    }
};