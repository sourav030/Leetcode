class Solution {
public:
    int solve(char ch) {
        if (ch == 'I') return 1;
        else if (ch == 'V') return 5;
        else if (ch == 'X') return 10;
        else if (ch == 'L') return 50;
        else if (ch == 'C') return 100;
        else if (ch == 'D') return 500;
        else if (ch == 'M') return 1000;
        return 0; // fallback
    }

    int romanToInt(string s) {
        int sum = 0;
        int n = s.length();

        for (int i = 0; i < n - 1; i++) {
            if (solve(s[i]) < solve(s[i + 1])) {
                sum -= solve(s[i]);
            } else {
                sum += solve(s[i]);
            }
        }

        // last character always added
        sum += solve(s[n - 1]);
        return sum;
    }
};
