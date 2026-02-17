class Solution {
public:
    int palindrome(string &str, int start, int end){
        if(start>=end){
            return 1;
        }
        if(str[start]!=str[end]){
            return 0;
        }
        return palindrome(str,start+1,end-1);
    }
    string longestPalindrome(string s) {
        int start;
        int len=INT_MIN;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(palindrome(s,i,j)){
                    if(len<j-i+1){

                    start=i;
                    len=j-i+1;
                    }
                }
            }
        }
        return s.substr(start,len);
    }
};