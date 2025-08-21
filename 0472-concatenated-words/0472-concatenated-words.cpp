class Solution {
public:
    bool isConcat(string &word, unordered_set<string>& st, unordered_map<string,bool>& memo) {
        if(memo.count(word)) return memo[word];

        int n = word.length();
        for(int i = 1; i < n; i++) {   
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);

            if(st.count(prefix)) {
                if(st.count(suffix) || isConcat(suffix, st, memo)) {
                    return memo[word] = true;
                }
            }
        }
        return memo[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> ans;

        unordered_map<string,bool> memo; 

        for(string &w : words) {
            if(w == "") continue;
            if(isConcat(w, st, memo)) {
                ans.push_back(w);
            }
        }
        return ans;
    }
};
