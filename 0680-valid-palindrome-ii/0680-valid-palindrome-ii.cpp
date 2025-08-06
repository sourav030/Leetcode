class Solution {
public:
    bool isPalindrome(int start, int end, string str){
        while(start<end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(s[start]!=s[end]){
                return isPalindrome(start+1,end,s) or isPalindrome(start,end-1,s);
            }
            start++;
            end--;
        }
        return true;
    }
};