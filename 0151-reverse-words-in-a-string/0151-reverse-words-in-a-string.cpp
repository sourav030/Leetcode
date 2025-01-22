class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        stack<string> st;

        // Traverse string to extract words
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                str += s[i];  // Add characters to the current word
            } else if (!str.empty()) {
                st.push(str);  // Push the word to the stack
                str = "";      // Reset the current word
            }
        }

        // Push the last word if not empty
        if (!str.empty()) {
            st.push(str);
        }

        // Construct the reversed sentence
        string ans = "";
        while (!st.empty()) {
            ans += st.top();  // Add word to the result
            st.pop();
            if (!st.empty()) {
                ans += " ";  // Add space between words
            }
        }

        return ans;
    }
};
