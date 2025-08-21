class Solution {
public:
    int n;
    vector<string> ans;

    bool isvalid(string tem) {
        if (tem.size() > 1 && tem[0] == '0') return false; // no leading zero
        int val = stoi(tem);
        return val <= 255;
    }

    void solve(string s, int idx, int part, string curr) {
        if (idx == n && part == 4) {
            curr.pop_back(); // remove trailing '.'
            ans.push_back(curr);
            return;
        }

        if (part >= 4 || idx >= n) return;

        // Case 1: length = 1
        if (idx + 1 <= n) {
            string temp = s.substr(idx, 1);
            if (isvalid(temp)) 
                solve(s, idx + 1, part + 1, curr + temp + ".");
        }

        // Case 2: length = 2
        if (idx + 2 <= n) {
            string temp = s.substr(idx, 2);
            if (isvalid(temp)) 
                solve(s, idx + 2, part + 1, curr + temp + ".");
        }

        // Case 3: length = 3
        if (idx + 3 <= n) {
            string temp = s.substr(idx, 3);
            if (isvalid(temp)) 
                solve(s, idx + 3, part + 1, curr + temp + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        if (n > 12 || n < 4) return ans;
        solve(s, 0, 0, "");
        return ans;
    }
};
