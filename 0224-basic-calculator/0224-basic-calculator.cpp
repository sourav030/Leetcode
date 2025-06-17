class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int number = 0;
        int result = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }
            else if (s[i] == '+') {
                result += number * sign;
                sign = 1;
                number = 0;
            }
            else if (s[i] == '-') {
                result += number * sign;
                sign = -1;
                number = 0;
            }
            else if (s[i] == '(') {
                // Push current result and sign to stack
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
                number = 0;
            }
            else if (s[i] == ')') {
                result += number * sign;
                number = 0;
                int prevSign = st.top(); st.pop();
                int prevResult = st.top(); st.pop();
                result = prevResult + prevSign * result;
            }
        }

        // Add the last number to result
        result += number * sign;
        return result;
    }
};
