class Solution {
public:
    string largestOddNumber(string num) {
        int a=num.length()-1;
        int n=num[a]-'0';
        if(n%2!=0) return num;

        string ans="";
        int index=-1;
        for(int i=0; i<num.length(); i++){
            int x=num[i]-'0';
            if(x%2!=0){
                index=i;
            }
        }
        if(index==-1) return ans;
        for(int i=0; i<=index; i++){
            ans+=num[i];
        }
        return ans;
    }
};