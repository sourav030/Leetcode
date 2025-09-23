class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int index=-1;
        for(int i=0; i<num.size(); i++){
            int val=num[i]-'0';
            if(val%2!=0){
                index=i;
            }
        }

        for(int i=0; i<=index; i++){
            ans+=num[i];
        }
        return ans;
    }
};