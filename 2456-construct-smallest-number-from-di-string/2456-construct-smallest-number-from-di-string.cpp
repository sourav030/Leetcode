class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        stack<int> st;

        for (int i = 0; i <= pattern.size(); i++) {
            st.push(i + 1);  // Always push the next number

            if (i == pattern.size() || pattern[i] == 'I') {
                // Pop all elements in the stack
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }

        return result;
    }
};
