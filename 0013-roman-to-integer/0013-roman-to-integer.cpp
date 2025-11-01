class Solution {
public:
    int solve(char a) {
        if (a == 'I') return 1;
        else if (a == 'V') return 5;
        else if (a == 'X') return 10;
        else if (a == 'L') return 50;
        else if (a == 'C') return 100;
        else if (a == 'D') return 500;
        else if (a == 'M') return 1000;
        return 0;
    }

    int romanToInt(string s) {
        int res = 0;
        int n = s.length();

        for (int i = 0; i < n - 1; i++) {
            if (solve(s[i]) < solve(s[i + 1])) {
                res -= solve(s[i]);
            } else {
                res += solve(s[i]);
            }
        }

    
        res += solve(s[n - 1]);
        return res;
    }
};
