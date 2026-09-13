class Solution {
public:
    int myAtoi(string s) {
        int k = 0;
        int sign = 1;
        long long ans = 0;

 
        while (k < s.length() && s[k] == ' ') {
            k++;
        }

    
        if (k < s.length() && (s[k] == '+' || s[k] == '-')) {
            if (s[k] == '-') {
                sign = -1;
            }
            k++;
        }

     
        while (k < s.length() && isdigit(s[k])) {

            ans = ans * 10 + (s[k] - '0');

          
            if (sign == 1 && ans > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -ans < INT_MIN) {
                return INT_MIN;
            }

            k++;
        }

        return ans * sign;
    }
};