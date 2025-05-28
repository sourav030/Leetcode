class Solution {
public:
    void fill(string word, int count[26]){
        for(int i=0; i<word.length(); i++){
            count[word[i]-'a']++;
        }
    }

    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        int count[26];
        for(int i=0; i<26; i++) count[i] = INT_MAX; 

        for(int i=0; i<words.size(); i++){
            int temp[26] = {0};
            fill(words[i], temp);
            for(int j=0; j<26; j++){
                count[j] = min(count[j], temp[j]);
            }
        }

        for(int i=0; i<26; i++){
            while(count[i]--){
                result.push_back(string(1, i + 'a'));
            }
        }

        return result;
    }
};
