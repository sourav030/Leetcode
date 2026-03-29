class Solution {
public:
    vector<string> ans;
    unordered_map<string,int> mp;

    void solve(string s, int idx, string temp){
      
        if(idx == s.length()){
            ans.push_back(temp);
            return;
        }

        string word = "";

        for(int i = idx; i < s.length(); i++){
            word += s[i];

            if(mp.find(word) != mp.end()){
                string newTemp;

                if(temp == ""){
                    newTemp = word;
                } else {
                    newTemp = temp + " " + word;
                }

                solve(s, i+1, newTemp);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto ele : wordDict){
            mp[ele]++;
        }

        solve(s, 0, "");
        return ans;
    }
};