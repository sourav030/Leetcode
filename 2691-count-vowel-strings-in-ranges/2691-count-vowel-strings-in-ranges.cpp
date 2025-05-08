class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        vector<int>prefix;
        int count=0;
        for(int i=0; i<words.size(); i++){
            string str=words[i];
            int n=str.length()-1;
           if (st.find(str[0]) != st.end() && st.find(str[n]) != st.end()){

                count++;
            }
            prefix.push_back(count);
        }
        vector<int>ans;
        for(int i=0; i<queries.size(); i++){
            int first=queries[i][0];
            int second=queries[i][1];
            int maxi=prefix[second];
            int mini= (first>0)?prefix[first-1]:0;
            ans.push_back(maxi-mini);
        }
        return ans;
    }
};