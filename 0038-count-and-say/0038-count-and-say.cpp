class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string say=countAndSay(n-1);
        string result="";
        int idx=0;
        while(idx<say.length()){
            int count=1;
            while(idx<say.length() and say[idx]==say[idx+1]){
                count++;
                idx++;
            }
            result+=to_string(count)+string(1,say[idx]);
            idx++;
        }
        return result;
    }
};