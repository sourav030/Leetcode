class Solution {
public:
  int calculate(string s) {
    stack<int> st;
    int number = 0;
    char sign = '+';
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (isdigit(c)) {
            number = number * 10 + (c - '0');
        }
        if ((!isdigit(c) && c != ' ') || i == n - 1) {
            if (sign == '+') {
                st.push(number);
            } else if (sign == '-') {
                st.push(-number);
            } else if (sign == '*') {
                int prev = st.top(); st.pop();
                st.push(prev * number);
            } else if (sign == '/') {
                int prev = st.top(); st.pop();
                st.push(prev / number);  // truncates toward zero
            }

            sign = c;
            number = 0;
        }
    }

    int result = 0;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

};