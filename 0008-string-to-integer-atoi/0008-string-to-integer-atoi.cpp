class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long ans = 0;     // use long to detect overflow
        int sign = 1;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Process digits
        while (i < n && isdigit(s[i])) {
            int val = s[i] - '0';
            ans = ans * 10 + val;

            // 4. Check overflow
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};
