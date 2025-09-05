class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string &str, int start, int end) {
        while (start < end) {
            if (str[start] != str[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void solve(vector<string>& arr, string &str, int index) {
        if (index >= str.length()) {
            ans.push_back(arr);
            return;
        }

        // Partition the string
        for (int i = index; i < str.length(); i++) {
            if (isPalindrome(str, index, i)) {
                arr.push_back(str.substr(index, i - index + 1));
                solve(arr, str, i + 1);
                arr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> arr;
        solve(arr, s, 0);
        return ans;
    }
};
