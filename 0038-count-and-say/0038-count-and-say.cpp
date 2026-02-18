class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string ans = countAndSay(n - 1);
        int count = 1;
        int idx = 1;
        string result = "";

        while (idx < ans.length()) {
            if (ans[idx] == ans[idx - 1]) {
                count++;
            } else {
                result += to_string(count) + ans[idx - 1];
                count = 1;
            }
            idx++;  
        }

        result += to_string(count) + ans.back();
        return result;
    }
};
