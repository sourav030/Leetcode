class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char c : tiles) {
            freq[c]++;
        }
        
        int result = 0;
        backtrack(freq, result);
        return result;
    }

private:
    void backtrack(unordered_map<char, int>& freq, int& result) {
        for (auto& [ch, count] : freq) {
            if (count > 0) {
                result++;
                freq[ch]--;
                backtrack(freq, result); // Recurse with one less of 'ch'
                freq[ch]++; // Backtrack, restore the count
            }
        }
    }
};
