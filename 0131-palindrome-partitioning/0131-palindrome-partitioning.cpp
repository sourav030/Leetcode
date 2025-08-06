class Solution {
public:
    vector<vector<string>> ans;
    vector<string> arr;
    
    void solve(int index, const string &str) {
        if (index >= str.length()) {
            ans.push_back(arr);
            return;
        }
        
        for (int i = index; i < str.length(); i++) {
            if (isPalindrome(index, i, str)) {  // pass end index, not length
                arr.push_back(str.substr(index, i - index + 1));
                solve(i + 1, str);
                arr.pop_back();
            }
        }
    }
    
    bool isPalindrome(int start, int end, const string &str) {
        while (start < end) {
            if (str[start] != str[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        solve(0, s);
        return ans;
    }
};
