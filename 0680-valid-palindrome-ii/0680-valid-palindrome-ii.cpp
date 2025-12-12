class Solution {
public:
    bool check(int start, int end, string str){
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
                if(check(start+1,end,s) or check(start,end-1,s)){
                    return true;
                }
                else{
                    return false;
                }
            }
            start++;
            end--;
        }
        return true;
    }
};