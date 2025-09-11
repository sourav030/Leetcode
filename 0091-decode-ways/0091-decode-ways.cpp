class Solution {
public:
    vector<int>arr;
    int solve(int idx, string s){
        if(s[idx]=='0'){
            return 0;
        }
        if(idx>=s.length()){
            return 1;
        }
        if(arr[idx]!=-1){
            return arr[idx];
        }
        int result=solve(idx+1,s);
        if(idx+1<s.length()){
            if(s[idx]=='1' or s[idx]=='2' and s[idx+1]<='6'){
                result+=solve(idx+2,s);
            }
        }
       return arr[idx]=result;
    }
    int numDecodings(string s) {
        arr.resize(s.length()+1,-1);
       return solve(0,s);
        
    }
};