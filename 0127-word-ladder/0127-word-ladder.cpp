class Solution {
public:
    unordered_set<string>st;
    void fill(string curr, queue<string>& q) {
    for (int j = 0; j < curr.size(); j++) {
        char original = curr[j];
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            if (ch == original) continue;

            curr[j] = ch;
            if (st.count(curr)) {
                q.push(curr);
                st.erase(curr); 
            }
        }
        curr[j] = original;  
    }
}

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto str:wordList){
            st.insert(str);
        }
        if(st.find(endWord)==st.end()){
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        int level=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==endWord){
                    return level;
                }
                fill(curr,q);
            }
            level++;
        }
        return 0;
    }
};