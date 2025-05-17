class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> ans;
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                ans.push_back(st.size() % 2);
                st.push(seq[i]);
            } else {
                st.pop();
                ans.push_back(st.size() % 2);
            }
        }
        return ans;
    }
};
