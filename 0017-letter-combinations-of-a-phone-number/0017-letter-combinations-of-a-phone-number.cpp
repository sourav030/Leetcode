class Solution {
public:
   unordered_map<char, string> mp {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
    vector<string>ans;
    void solve(int index,string digits,string result){
        if(index==digits.size()){
            ans.push_back(result);
        }
        for(auto i:mp[digits[index]]){
            result.push_back(i);
            solve(index+1,digits,result);
            result.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        string result;
        solve(0,digits,result);
        return ans;
    }
};