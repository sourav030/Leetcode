class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end){
            while (start < end && !isalnum(s[start])) {
                start++;
            }

            while (start < end && !isalnum(s[end])) {
                end--;
            }

            char ch1= tolower(s[start]);
            char ch2=tolower(s[end]);
            if(ch1!=ch2){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};