class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length()-1;
        int count=0;
        while(n){
            if(!isalpha(s[n])){
                n--;
            }
            else{
                break;
            }

        }
        for(int i=n; i>=0; i--){
            if(isalpha(s[i])){
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};