class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // remove remaining digits
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string str = "";
        while (!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());

      
        int i = 0;
        while (i < str.size() && str[i] == '0') i++;
        str = str.substr(i);

        return str.empty() ? "0" : str;
    }
};
