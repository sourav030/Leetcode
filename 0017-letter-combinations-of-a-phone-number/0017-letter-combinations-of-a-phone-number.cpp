class Solution {
public:
    map<int,string>mp;
    vector<string>arr;
    void solve(string digits, int idx, string &str){
        if(idx>=digits.length()){
            if(str.length()==digits.length())
            arr.push_back(str);
            return;
        }
        for(auto ele:mp[digits[idx]-'0']){
            str.push_back(ele);
            solve(digits,idx+1,str);
            str.pop_back();
            solve(digits,idx+1,str);
        }
    }
    vector<string> letterCombinations(string digits) {
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string str;
        solve(digits,0,str);
        return arr;
    }
};